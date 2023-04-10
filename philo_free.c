/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 05:16:39 by amait-ou          #+#    #+#             */
/*   Updated: 2023/04/10 22:53:28 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_free(t_all *all)
{
	int	i;

	i = 0;
	while (i < all->number)
	{
		pthread_mutex_destroy(&all->mutex[i]);
		pthread_mutex_destroy(&all->philo[i].meal_assigning);
		pthread_mutex_destroy(&all->philo[i].meal_timing);
		++i;
	}
	pthread_mutex_destroy(&all->print);
	free(all->philo);
}
