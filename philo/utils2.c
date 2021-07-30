/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahnys <ahnys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 21:41:13 by ahnys             #+#    #+#             */
/*   Updated: 2021/07/30 21:52:47 by ahnys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	clear_info(t_info *info)
{
	int	i;

	if (info->forks)
	{
		i = 0;
		while (i < info->num_philo)
			pthread_mutex_destroy(&info->forks[i++]);
		free(info->forks);
	}
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
