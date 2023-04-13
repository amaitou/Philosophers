/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 05:06:08 by amait-ou          #+#    #+#             */
/*   Updated: 2023/04/12 08:24:10 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_ul	get_time(void)
{
	struct timeval	t;
	t_ul			msc;

	gettimeofday(&t, NULL);
	msc = t.tv_sec * 1000 + t.tv_usec / 1000;
	return (msc);
}

int	_usleep(t_ul _sleep)
{
	t_ul	start;

	start = get_time();
	while (get_time() - start < _sleep)
		usleep(200);
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

void	write_locker(char *s, t_philo *philo)
{
	pthread_mutex_lock(&philo->all->write);
	printf("%lu %d %s\n", get_time() - \
		philo->all->s_time, philo->id + 1, s);
	pthread_mutex_unlock(&philo->all->write);
}

void	philo_free(t_philo *philo)
{
	free(philo->all->mutex);
	free(philo->all);
	free(philo);
}
