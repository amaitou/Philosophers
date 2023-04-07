/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 04:30:31 by amait-ou          #+#    #+#             */
/*   Updated: 2023/04/07 21:56:52 by amait-ou         ###   ########.fr       */
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
		pthread_mutex_lock(philo->print);
		printf(MSG, BLUE, get_time() - philo->s_time, philo->id, THINKING, WHITE);
		pthread_mutex_unlock(philo->print);

		pthread_mutex_lock(philo->left);
		
		pthread_mutex_lock(philo->print);
		printf(MSG, WHITE ,get_time() - philo->s_time, philo->id, FORKING, WHITE);
		pthread_mutex_unlock(philo->print);
		
		pthread_mutex_lock(philo->right);
		
		pthread_mutex_lock(philo->print);
		printf(MSG,WHITE, get_time() - philo->s_time, philo->id, FORKING, WHITE);
		pthread_mutex_unlock(philo->print);
		
		pthread_mutex_lock(philo->print);
		printf(MSG, GREEN, get_time() - philo->s_time, philo->id, EATING, WHITE);
		pthread_mutex_unlock(philo->print);
		
		philo->l_meal = get_time();
		philo->n_meals++;
		_usleep(philo->t_eat);

		pthread_mutex_unlock(philo->left);
		pthread_mutex_unlock(philo->right);
		
		
		pthread_mutex_lock(philo->print);
		printf(MSG, YELLOW, get_time() - philo->s_time, philo->id, SLEEPING, WHITE);
		pthread_mutex_unlock(philo->print);
		
		_usleep(philo->t_sleep);
	}
	return (NULL);
}