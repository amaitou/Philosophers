/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 21:52:40 by amait-ou          #+#    #+#             */
/*   Updated: 2023/03/27 00:36:30 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **ag)
{
	t_philo	philo;

	if (ac >= 5)
	{
		philo.num = ac;
		allocate_philo(&philo);
		allocate_mutex(&philo);
		initialize_philo(&philo, ag);
	}
	return (0);
}
