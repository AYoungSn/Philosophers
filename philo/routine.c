/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahnys <ahnys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 17:39:34 by ahnys             #+#    #+#             */
/*   Updated: 2021/08/15 14:37:29 by ahnys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *p)
{
	t_philo		*philo;
	pthread_t	tid;

	philo = (t_philo *)p;
	if (pthread_create(&tid, NULL, &monitor, philo) != 0)
		return ((void *)1);
	pthread_detach(tid);
	while (1)
	{
		if (philo->info->isDead)
			return ((void *)1);
		take_forks(philo);
		if (philo->info->isDead)
			return ((void *)1);
		philo_eat(philo);
		if (philo->info->isDead)
			return ((void *)1);
		philo_sleep(philo);
		if (philo->info->isDead)
			return ((void *)1);
		print_msg(philo, T_THINK);
		usleep(200);
	}
}

void	take_forks(t_philo *philo)
{
	if (philo->info->isDead)
		return ;
	if (philo->position == 0)
	{
		pthread_mutex_lock(&philo->info->forks[philo->rfork]);
		print_msg(philo, T_FORK);
		pthread_mutex_lock(&philo->info->forks[philo->lfork]);
		print_msg(philo, T_FORK);
		return ;
	}
	pthread_mutex_lock(&philo->info->forks[philo->lfork]);
	print_msg(philo, T_FORK);
	pthread_mutex_lock(&philo->info->forks[philo->rfork]);
	print_msg(philo, T_FORK);
}

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex);
	philo->is_eating = 1;
	philo->last_eat = get_time() - philo->info->start;
	print_msg(philo, T_EAT);
	philo->limit = philo->last_eat + philo->info->t_die;
	ft_sleep(philo->info->t_eat);
	if (philo->info->isDead)
		return ;
	philo->eat_count++;
	philo->is_eating = 0;
	pthread_mutex_unlock(&philo->mutex);
	pthread_mutex_unlock(&philo->eat_m);
}

void	philo_sleep(t_philo *philo)
{
	print_msg(philo, T_SLP);
	if (philo->info->isDead)
		return ;
	pthread_mutex_unlock(&philo->info->forks[philo->rfork]);
	pthread_mutex_unlock(&philo->info->forks[philo->lfork]);
	ft_sleep(philo->info->t_sleep);
}
