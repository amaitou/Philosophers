/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 22:49:03 by amait-ou          #+#    #+#             */
/*   Updated: 2023/03/27 00:52:19 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	current_time(t_philo *philo)
{
	long	msc;

	gettimeofday(philo->time, NULL);
	msc = philo->time->tv_sec * 1000 + philo->time->tv_usec / 1000;
	return (msc);
}
