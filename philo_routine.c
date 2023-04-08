/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 04:30:31 by amait-ou          #+#    #+#             */
/*   Updated: 2023/04/08 02:50:58 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep(1000);
	while (1)
	{
		print_locker(THINKING, philo, BLUE);
		pthread_mutex_lock(philo->left);
		print_locker(FORKING, philo, YELLOW);
		pthread_mutex_lock(philo->right);
		print_locker(FORKING, philo, YELLOW);
		print_locker(EATING, philo, GREEN);
		philo->l_meal = get_time();
		philo->n_meals++;
		_usleep(philo->t_eat);
		pthread_mutex_unlock(philo->left);
		pthread_mutex_unlock(philo->right);
		print_locker(SLEEPING, philo, RED);
		_usleep(philo->t_sleep);
	}
	return (NULL);
}
