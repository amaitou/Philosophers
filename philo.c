/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 05:08:30 by amait-ou          #+#    #+#             */
/*   Updated: 2023/04/13 05:32:52 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	is_eaten(t_philo *philo)
{
	if (philo->n_eaten == philo->all->m_meals \
		&& philo->all->m_meals)
		philo->reached_eat = 1;
}

int	check_meals(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->all->n_philos)
	{
		if (philo[i].reached_eat != 1)
			return (0);
	}
	return (1);
}

void	is_dead(t_philo *philo)
{
	if (get_time() - philo->l_meal >= philo->all->t_die)
		philo->is_dead = 1;
}

void	philo_checker(t_philo *philo)
{
	int	i;

	i = 0;
	while (1)
	{
		pthread_mutex_lock(&philo->all->death);
		is_eaten(&philo[i]);
		if (check_meals(philo))
			return ;
		is_dead(&philo[i]);
		if (philo[i].is_dead)
		{
			pthread_mutex_lock(&philo->all->write);
			printf("%lu %d %s\n", get_time() - \
				philo->all->s_time, philo->id + 1, DIED);
			return ;
		}
		i = (i + 1) % philo->all->n_philos;
		pthread_mutex_unlock(&philo->all->death);
	}
}

int	main(int ac, char **ag)
{
	t_all	*all;
	t_philo	*philo;

	if (ac >= 5)
	{
		if (philo_atoi(ag[1]) <= 0 || philo_atoi(ag[2]) <= 0
			|| philo_atoi(ag[3]) <= 0 || philo_atoi(ag[4]) <= 0
			|| (ag[5] && philo_atoi(ag[5]) <= 0))
			return (0);
		all = all_init(ag);
		if (!all)
			return (printf("Failed to run the program\n"));
		philo = philo_init(all);
		if (!philo)
			return (printf("Failed to run the program\n"));
		thread_create(philo);
		philo_checker(philo);
		philo_detach(philo);
	}
	else
		printf("[!] Missing Arguments\n");
	return (0);
}
