/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 00:19:06 by amait-ou          #+#    #+#             */
/*   Updated: 2023/04/08 05:22:05 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_arguments(char **ag)
{
	if (philo_atoi(ag[1]) <= 0 || philo_atoi(ag[2]) <= 0
		|| philo_atoi(ag[3]) <= 0 || philo_atoi(ag[4]) <= 0
		|| (ag[5] && philo_atoi(ag[5]) <= 0))
		return (0);
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
			if (all->philo[i].n_meals == all->philo[i].m_meals)
			{
				c++;
				_usleep(50);
				if (c == all->number)
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
