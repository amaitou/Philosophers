/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 01:56:44 by amait-ou          #+#    #+#             */
/*   Updated: 2023/04/08 20:54:22 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	mutex_init(t_all *all)
{
	int	i;

	i = 0;
	all->mutex = malloc(sizeof(pthread_mutex_t) * all->number);
	if (!all->mutex)
		return ;
	while (i < all->number)
	{
		pthread_mutex_init(&all->mutex[i], NULL);
		++i;
	}
	pthread_mutex_init(&all->print, NULL);
}

void	philosopher_init(t_all *all)
{
	int		i;
	t_ll	t;

	i = 0;
	t = get_time();
	while (i < all->number)
	{
		all->philo[i].id = i + 1;
		all->philo[i].l_meal = t;
		all->philo[i].n_meals = 0;
		all->philo[i].t_die = philo_atoi(all->times[2]);
		all->philo[i].t_eat = philo_atoi(all->times[3]);
		all->philo[i].t_sleep = philo_atoi(all->times[4]);
		if (all->times[5])
			all->philo[i].m_meals = philo_atoi(all->times[5]);
		else
			all->philo[i].m_meals = 0;
		all->philo[i].print = &all->print;
		all->philo[i].left = &all->mutex[i];
		all->philo[i].right = &all->mutex[(i + 1) % all->number];
		all->philo[i].s_time = t;
		all->philo[i].n_eat = 0;
		++i;
	}
}

void	all_init(t_all *all, char **ag)
{
	all->number = philo_atoi(ag[1]);
	all->times = ag;
	all->philo = malloc(sizeof(t_philo) * all->number);
	if (!all->philo)
		return ;
}

void	thread_create(t_all *all)
{
	int	i;

	i = 0;
	while (i < all->number)
	{
		pthread_create(&all->philo[i].thread, NULL, &routine, &all->philo[i]);
		++i;
	}
}
