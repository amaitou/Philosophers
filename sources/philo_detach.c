/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_detach.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 03:06:25 by amait-ou          #+#    #+#             */
/*   Updated: 2024/01/31 03:21:33 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*philo_detach(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->all->n_philos)
		pthread_detach(philo[i].thread);
	i = -1;
	while (++i < philo->all->n_philos)
		pthread_mutex_destroy(&philo->all->mutex[i]);
	pthread_mutex_destroy(&philo->all->write);
	pthread_mutex_destroy(&philo->all->death);
	philo_free(philo);
	return ((void *)0);
}
