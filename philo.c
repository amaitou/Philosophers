/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 05:08:30 by amait-ou          #+#    #+#             */
/*   Updated: 2023/04/10 03:58:01 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **ag)
{
	t_all	all;

	if (ac >= 5)
	{
		if (philo_atoi(ag[1]) <= 0 || philo_atoi(ag[2]) <= 0
			|| philo_atoi(ag[3]) <= 0 || philo_atoi(ag[4]) <= 0
			|| (ag[5] && philo_atoi(ag[5]) <= 0))
			return (0);
		all_init(&all, ag);
		mutex_init(&all);
		philosopher_init(&all);
		thread_create(&all);
		philo_checker(&all);
	}
	else
		printf("%s[!] Missing Arguments\n", RED);
	return (0);
}
