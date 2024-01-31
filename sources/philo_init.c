/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 01:56:44 by amait-ou          #+#    #+#             */
/*   Updated: 2024/01/31 03:21:42 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	fork_init(t_all *all)
{
	all->mutex = malloc(sizeof(pthread_mutex_t) * all->n_philos);
	if (!all->mutex)
		return (1);
	return (0);
}

void	mutex_init(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->all->n_philos)
		pthread_mutex_init(&philo->all->mutex[i], NULL);
	pthread_mutex_init(&philo->all->write, NULL);
	pthread_mutex_init(&philo->all->death, NULL);
}

t_all	*all_init(char **ag)
{
	t_all	*all;

	all = malloc(sizeof(t_all) * 1);
	if (!all)
		return ((void *)0);
	all->n_philos = philo_atoi(ag[1]);
	all->t_die = philo_atoi(ag[2]);
	all->t_eat = philo_atoi(ag[3]);
	all->t_sleep = philo_atoi(ag[4]);
	if (ag[5])
		all->m_meals = philo_atoi(ag[5]);
	else
		all->m_meals = 0;
	if (fork_init(all))
	{
		free(all);
		return ((void *)0);
	}
	all->s_time = get_time();
	return (all);
}

t_philo	*philo_init(t_all *all)
{
	t_philo	*philo;
	t_ul	time;
	int		i;

	philo = malloc(sizeof(t_philo) * all->n_philos);
	time = get_time();
	if (!philo)
	{
		free(all->mutex);
		free(all);
		return ((void *)0);
	}
	i = -1;
	while (++i < all->n_philos)
	{
		philo[i].all = all;
		philo[i].id = i;
		philo[i].l_meal = time;
		philo[i].n_eaten = 0;
		philo[i].is_dead = 0;
		philo[i].reached_eat = 0;
	}
	return (philo);
}

void	thread_create(t_philo *philo)
{
	int	i;

	i = 0;
	mutex_init(philo);
	while (i < philo->all->n_philos)
	{
		pthread_create(&philo[i].thread, NULL, &routine, &philo[i]);
		i += 2;
		usleep(5);
	}
	usleep(200);
	i = 1;
	while (i < philo->all->n_philos)
	{
		pthread_create(&philo[i].thread, NULL, &routine, &philo[i]);
		i += 2;
	}
}
