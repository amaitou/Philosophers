/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 19:14:47 by amait-ou          #+#    #+#             */
/*   Updated: 2023/03/27 00:52:01 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

# define MSG "%lu |%d| %s\n"

typedef struct timeval	t_time;

typedef struct items
{
	int				id;
	pthread_t		thread;
	int32_t			eat;
	int32_t			sleep;
	int32_t			die;
	int				meals;
	pthread_mutex_t	left_fork;
	pthread_mutex_t	right_fork;
}	t_items;

typedef struct mutexes
{
	pthread_mutex_t	mutex;
}	t_mutex;

typedef struct philosophers
{
	int					num;
	pthread_mutex_t		*mutexes;
	t_items				*philo;
	t_time				*time;
}	t_philo;

void	allocate_philo(t_philo *philo);
void	allocate_mutex(t_philo *philo);
void	initialize_philo(t_philo *philo, char **ag);
void	create_threads(t_philo *philo);
void	*philospher_thread(t_philo *philo);
long	current_time(t_philo *philo);
int		philosopher_atoi(const char *str);

#endif