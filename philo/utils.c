/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahnys <ahnys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 21:40:59 by ahnys             #+#    #+#             */
/*   Updated: 2021/08/15 14:01:54 by ahnys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
** micro seconds : 1 / 1,000,000
** milli seconds : 1 / 1,000
** timeval { time_t tv_sec; (seconds)
**			suseconds_t tv_usec; (microseconds)}
*/
uint64_t	get_time(void)
{
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

int	mutex_init(t_info *info)
{
	int		i;

	pthread_mutex_init(&info->wri, NULL);
	pthread_mutex_init(&info->somebody_dead, NULL);
	pthread_mutex_lock(&info->somebody_dead);
	info->forks = malloc(sizeof(pthread_mutex_t) * info->num_philo);
	if (!info->forks)
		return (0);
	i = 0;
	while (i < info->num_philo)
		pthread_mutex_init(&(info->forks[i++]), NULL);
	return (1);
}

static void	init_philos(t_info *info)
{
	int		i;

	i = 0;
	info->philos = malloc(sizeof(t_philo) * info->num_philo);
	if (!info->philos)
		return ;
	while (i < info->num_philo)
	{
		info->philos[i].eat_count = 0;
		info->philos[i].is_eating = 0;
		info->philos[i].position = i;
		info->philos[i].lfork = i;
		info->philos[i].rfork = (i + 1) % info->num_philo;
		info->philos[i].info = info;
		info->philos[i].last_eat = 0;
		info->philos[i].limit = info->t_die;
		pthread_mutex_init(&info->philos[i].mutex, NULL);
		pthread_mutex_init(&info->philos[i].eat_m, NULL);
		pthread_mutex_lock(&info->philos[i].eat_m);
		i++;
	}
}

int	init_info(t_info *info)
{
	init_philos(info);
	info->isDead = 0;
	return (mutex_init(info));
}
