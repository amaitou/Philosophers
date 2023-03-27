/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 20:49:46 by amait-ou          #+#    #+#             */
/*   Updated: 2023/03/27 00:46:04 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	allocate_philo(t_philo *philo)
{
	philo->philo = malloc(sizeof(philo->philo) * philo->num);
	if (!philo->philo)
		return ;
}

void	allocate_mutex(t_philo *philo)
{
	philo->mutexes = malloc(sizeof(philo->mutexes) * philo->num);
	if (!philo->mutexes)
		return ;
}

void	initialize_philo(t_philo *philo, char **ag)
{
	int	i;

	i = 0;
	while (i < philo->num)
	{
		philo->philo[i].id = i + 1;
		philo->philo[i].die = philosopher_atoi(ag[2]) * 1000;
		philo->philo[i].eat = philosopher_atoi(ag[3]) * 1000;
		philo->philo[i].sleep = philosopher_atoi(ag[4]) * 1000;
		if (philosopher_atoi(ag[5]))
			philo->philo[i].meals = philosopher_atoi(ag[5]);
		else
			philo->philo[i].meals = 0;
		philo->philo[i].left_fork = philo->mutexes[i];
		philo->philo[i].right_fork = (philo->mutexes[(i + 1) % philo->num]);
		++i;
	}
}

// void	create_threads(t_philo *philo)
// {
// 	int	i;

// 	i = 0;
// 	while (i < philo->num)
// 	{
// 		if (pthread_create(philo->philo + i, NULL, &philospher_thread, NULL))
// 			return ;
// 		++i;
// 	}
// }
