/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 05:08:30 by amait-ou          #+#    #+#             */
/*   Updated: 2023/04/07 22:07:59 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **ag)
{
	t_all	all;
	int		i;
	int		c;

	if (ac >= 5)
	{
		c = 0;
		if (philo_atoi(ag[1]) <= 0 || philo_atoi(ag[2]) <= 0 || philo_atoi(ag[3]) <= 0 || philo_atoi(ag[4]) <= 0
			|| (ag[5] && philo_atoi(ag[5]) <= 0))
		{
			printf("Invalid");
			return (0);
		}
		all.number = philo_atoi(ag[1]);
		all.times = ag;
		all.philo = malloc(sizeof(t_philo) * all.number);
		if (!all.philo)
			return (0);
		mutex_init(&all);
		philosopher_init(&all);
		thread_create(&all);
		while (1)
		{
			i = 0;
			while (i < all.number)
			{
				if (get_time() - all.philo[i].l_meal >= all.philo[i].t_die)
				{
					pthread_mutex_lock(&all.print);
					printf(MSG, BLUE, get_time() - all.philo[i].s_time,
						all.philo[i].id, DIED, WHITE);
					return (0);
				}
				else if (all.philo[i].n_meals == all.philo[i].m_meals)
					c++;
				if (c == all.number)
					return (0);
				++i;
			}
			i = 0;
		}
	}
	return (0);
}
