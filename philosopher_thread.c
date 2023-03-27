/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_thread.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 22:47:34 by amait-ou          #+#    #+#             */
/*   Updated: 2023/03/27 00:53:10 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*philospher_thread(t_philo *philo)
{
	while (1)
	{
		pthread_mutex_lock(&philo->philo->left_fork);
		pthread_mutex_lock(&philo->philo->right_fork);
		printf(MSG, current_time(philo),
			philo->philo->id, "has taken a fork\n");
		printf(MSG, current_time(philo),
			philo->philo->id, "is eating");
		usleep(philo->philo->eat);
		pthread_mutex_unlock(&philo->philo->left_fork);
		pthread_mutex_unlock(&philo->philo->right_fork);
	}
	return (NULL);
}
