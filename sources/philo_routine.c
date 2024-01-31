/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 04:30:31 by amait-ou          #+#    #+#             */
/*   Updated: 2024/01/31 03:21:47 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->all->mutex[(philo->id + 1) % \
		philo->all->n_philos]);
	write_locker(FORKING, philo);
	pthread_mutex_lock(&philo->all->mutex[philo->id]);
	write_locker(FORKING, philo);
	write_locker(EATING, philo);
	pthread_mutex_lock(&philo->all->death);
	philo->l_meal = get_time();
	pthread_mutex_unlock(&philo->all->death);
	_usleep(philo->all->t_eat);
	pthread_mutex_lock(&philo->all->death);
	philo->n_eaten++;
	pthread_mutex_unlock(&philo->all->death);
	pthread_mutex_unlock(&philo->all->mutex[(philo->id + 1) % \
		philo->all->n_philos]);
	pthread_mutex_unlock(&philo->all->mutex[philo->id]);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = arg;
	while (1)
	{
		write_locker(THINKING, philo);
		eating(philo);
		write_locker(SLEEPING, philo);
		_usleep(philo->all->t_sleep);
	}
	return ((void *)0);
}
