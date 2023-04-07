/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 05:06:08 by amait-ou          #+#    #+#             */
/*   Updated: 2023/04/06 02:58:54 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_ll	get_time(void)
{
	struct timeval	t;
	t_ll			msc;

	gettimeofday(&t, NULL);
	msc = t.tv_sec * 1000 + t.tv_usec / 1000;
	return (msc);
}

int	_usleep(t_ll _sleep)
{
	t_ll	start;

	start = get_time();
	while (1)
	{
		if (get_time() - start == _sleep)
			return (0);
		usleep(100);
	}
	return (0);
}

int	philo_atoi(const char *str)
{
	char	*p;
	int		s;
	int		r;

	p = (char *)str;
	s = 1;
	r = 0;
	while (*p == ' ' || *p == '\n' || *p == '\t' || *p == '\f'
		|| *p == '\v' || *p == '\r')
		++p;
	if (*p == '-' || *p == '+')
	{
		if (*p == '-')
			s *= -1;
		++p;
	}
	while (*p >= '0' && *p <= '9')
	{
		r = r * 10 + *p - 48;
		++p;
	}
	return (r * s);
}

void	philo_msg(char *s, int id, pthread_mutex_t *print, t_ll time)
{
	pthread_mutex_lock(print);
	printf(MSG, GREEN, get_time() - time, id, s, WHITE);
	pthread_mutex_unlock(print);
}
