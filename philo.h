/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 00:55:18 by amait-ou          #+#    #+#             */
/*   Updated: 2023/04/08 05:21:46 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

# define MSG "%s%lld %d %s%s\n"

# define EATING "is eating"
# define SLEEPING "is sleeping"
# define THINKING "is thinking"
# define FORKING "has taken a fork"
# define DIED "died"

# define RED "\x1B[31m"
# define BLUE "\x1B[34m"
# define YELLOW "\x1B[33m"
# define GREEN "\x1B[32m" 
# define WHITE "\x1B[37m"

typedef long long	t_ll;

typedef struct s_philo
{
	int				id;
	t_ll			t_die;
	t_ll			t_eat;
	t_ll			t_sleep;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	pthread_t		thread;
	t_ll			l_meal;
	int				n_meals;
	int				m_meals;
	t_ll			s_time;
	pthread_mutex_t	*print;
}	t_philo;

typedef struct s_all
{
	pthread_mutex_t	*mutex;
	pthread_mutex_t	print;
	t_philo			*philo;
	int				number;
	char			**times;
}	t_all;

t_ll	get_time(void);
int		_usleep(t_ll _sleep);
int		philo_atoi(const char *str);
void	mutex_init(t_all *all);
void	philosopher_init(t_all *all);
void	*routine(void *arg);
void	thread_create(t_all *all);
int		philo_arguments(char **ag);
void	all_init(t_all *all, char **ag);
void	philo_checker(t_all *all);
void	print_locker(char *s, t_philo *philo, char *c);
void	philo_free(t_all *all);

#endif