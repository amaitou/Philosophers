/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 00:19:06 by amait-ou          #+#    #+#             */
/*   Updated: 2023/04/08 22:49:14 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_arguments(char **ag)
{
	if (philo_atoi(ag[1]) <= 0 || philo_atoi(ag[2]) <= 0
		|| philo_atoi(ag[3]) <= 0 || philo_atoi(ag[4]) <= 0
		|| (ag[5] && philo_atoi(ag[5]) < 0))
		return (0);
	return (1);
}

static void	check_meals(t_philo *philo)
{
	if (philo->n_meals >= philo->m_meals
		&& philo->m_meals)
		philo->n_eat = 1;
}

static int	check_eaten(t_all *all)
{
	int	i;

	i = 0;
	while (i < all->number)
	{
		if (all->philo[i].n_eat != 1)
			return (0);
		++i;
	}
	return (1);
}

void	philo_checker(t_all *all)
{
	int	i;
	int	c;

	c = 0;
	while (1)
	{
		i = -1;
		while (++i < all->number)
		{
			check_meals(&all->philo[i]);
			if (check_eaten(all))
			{
				philo_free(all);
				return ;
			}
			else if (get_time() - all->philo[i].l_meal >= all->philo[i].t_die)
			{
				pthread_mutex_lock(&all->print);
				printf(MSG, BLUE, get_time() - all->philo[i].s_time,
					all->philo[i].id, DIED, WHITE);
				philo_free(all);
				return ;
			}
		}
	}
}
