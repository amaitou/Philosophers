/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 05:08:30 by amait-ou          #+#    #+#             */
/*   Updated: 2023/04/08 05:08:33 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **ag)
{
	t_all	all;

	if (ac >= 5)
	{
		if (!philo_arguments(ag))
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