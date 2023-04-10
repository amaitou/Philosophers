/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 04:30:31 by amait-ou          #+#    #+#             */
/*   Updated: 2023/04/10 05:15:29 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static	void	meal_assign_locker(t_philo *philo)
{
	pthread_mutex_lock(&philo->meal_assigning);
	philo->l_meal = get_time();
	pthread_mutex_unlock(&philo->meal_assigning);
}

static	void	meal_time_locker(t_philo *philo)
{
	pthread_mutex_lock(&philo->meal_timing);
	philo->n_meals++;
	pthread_mutex_unlock(&philo->meal_timing);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep(1000);
	while (1)
	{
		print_locker(THINKING, philo, YELLOW);
		pthread_mutex_lock(philo->left);
		print_locker(FORKING, philo, WHITE);
		pthread_mutex_lock(philo->right);
		print_locker(FORKING, philo, WHITE);
		print_locker(EATING, philo, GREEN);
		meal_assign_locker(philo);
		meal_time_locker(philo);
		_usleep(philo->t_eat);
		pthread_mutex_unlock(philo->left);
		pthread_mutex_unlock(philo->right);
		print_locker(SLEEPING, philo, BLUE);
		_usleep(philo->t_sleep);
	}
	return (NULL);
}
