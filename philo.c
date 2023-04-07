/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 05:08:30 by amait-ou          #+#    #+#             */
/*   Updated: 2023/04/07 08:00:07 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **ag)
{
	t_all	all;

	if (ac >= 5)
	{
		all.number = philo_atoi(ag[1]);
		all.times = ag;
		all.philo = malloc(sizeof(t_philo) * all.number);
		if (!all.philo)
			return (0);
		mutex_init(&all);
		philosopher_init(&all);
		thread_create(&all);
	}
	while (1)
		;
	return (0);
}
