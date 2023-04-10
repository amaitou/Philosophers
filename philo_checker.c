/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 00:19:06 by amait-ou          #+#    #+#             */
/*   Updated: 2023/04/10 05:17:10 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	check_meals(t_philo *philo)
{
	pthread_mutex_lock(&philo->meal_assigning);
	if (philo->n_meals >= philo->m_meals && philo->m_meals)
		philo->n_eat = 1;
	pthread_mutex_unlock(&philo->meal_assigning);
}

static void	check_death(t_philo *philo)
{
	if (get_time() - philo->l_meal > philo->t_die)
		philo->is_dead = 1;
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

void	death_helper(t_philo *philo, t_all *all)
{
	pthread_mutex_lock(&all->print);
	printf(MSG, BLUE, get_time() - philo->s_time,
		all->philo->id, DIED, RED);
	philo_free(all);
}

void	philo_checker(t_all *all)
{
	int	i;

	while (1)
	{
		i = -1;
		while (++i < all->number)
		{
			check_meals(&all->philo[i]);
			pthread_mutex_lock(&all->philo[i].meal_timing);
			if (check_eaten(all))
			{
				philo_free(all);
				return ;
			}
			check_death(&all->philo[i]);
			if (all->philo[i].is_dead)
			{
				death_helper(&all->philo[i], all);
				return ;
			}
			pthread_mutex_unlock(&all->philo[i].meal_timing);
		}
	}
}
