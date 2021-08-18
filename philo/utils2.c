/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahnys <ahnys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 21:41:13 by ahnys             #+#    #+#             */
/*   Updated: 2021/08/18 13:58:10 by yoahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	clear_fork(t_info *info)
{
	int	i;

	if (info->forks)
	{
		i = 0;
		while (i < info->num_philo)
		{
			pthread_join(info->philos[i].tid, 0);
			pthread_mutex_destroy(&info->forks[i++]);
		}
		free(info->forks);
	}
}

int	clear_info(t_info *info)
{
	int	i;

	usleep(info->t_die * 1000);
	clear_fork(info);
	if (info->philos)
	{
		i = 0;
		while (i < info->num_philo)
		{
			pthread_mutex_destroy(&info->philos[i].mutex);
			pthread_mutex_destroy(&info->philos[i].eat_m);
			i++;
		}
		free(info->philos);
	}
	pthread_mutex_destroy(&info->wri);
	pthread_mutex_destroy(&info->somebody_dead);
	return (1);
}

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	argu_check(t_info *info, int argc, char *argv[])
{
	int	i;
	int	j;

	if (argc < 5 || argc > 6)
		return (1);
	info->num_philo = ft_atoi(argv[1]);
	info->t_die = ft_atoi(argv[2]);
	info->t_eat = ft_atoi(argv[3]);
	info->t_sleep = ft_atoi(argv[4]);
	info->ntime_eat = -1;
	if (argc == 6)
		info->ntime_eat = ft_atoi(argv[5]);
	j = argc;
	while (argc-- > 1)
	{
		i = 0;
		while (argv[argc][i])
			if (!ft_isdigit(argv[argc][i++]))
				return (1);
	}
	if (info->num_philo < 1 || info->t_die < 0
		|| info->t_eat < 0 || info->t_sleep < 0
		|| (j == 6 && info->ntime_eat < 0))
		return (1);
	return (0);
}
