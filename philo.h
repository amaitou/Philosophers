/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 00:55:18 by amait-ou          #+#    #+#             */
/*   Updated: 2023/04/13 05:35:04 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

# define MSG "%lld %d %s\n"

# define THINKING "is thinking"
# define FORKING "has taken a fork"
# define EATING "is eating"
# define SLEEPING "is sleeping"
# define DIED "died"

typedef unsigned long	t_ul;

typedef struct s_all
{
	int				n_philos;
	int				m_meals;
	t_ul			t_die;
	t_ul			t_eat;
	t_ul			t_sleep;
	t_ul			s_time;
	pthread_mutex_t	write;
	pthread_mutex_t	death;
	pthread_mutex_t	*mutex;
}	t_all;

typedef struct s_philo
{
	int				id;
	int				is_dead;
	int				n_eaten;
	pthread_t		thread;
	int				reached_eat;
	t_ul			l_meal;
	t_all			*all;
}	t_philo;

t_all	*all_init(char **ag);
t_philo	*philo_init(t_all *all);
void	*routine(void *arg);
void	thread_create(t_philo *philo);
t_ul	get_time(void);
int		philo_atoi(const char *str);
int		_usleep(t_ul _sleep);
void	write_locker(char *s, t_philo *philo);
void	mutex_init(t_philo *philo);
void	philo_free(t_philo *philo);
void	*philo_detach(t_philo *philo);

#endif