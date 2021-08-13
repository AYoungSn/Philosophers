/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahnys <ahnys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 21:40:29 by ahnys             #+#    #+#             */
/*   Updated: 2021/08/13 14:23:58 by ahnys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitor(void *p)
{
	t_philo	*philo;

	philo = p;
	pthread_mutex_lock(&philo->info->wri);
	// write(1, "monitor\n", 8);
	pthread_mutex_unlock(&philo->info->wri);
	while (1)
	{
		pthread_mutex_lock(&philo->mutex);
		if (!philo->is_eating && get_time() > philo->limit)
		{
			print_msg(philo, T_DIE);
			pthread_mutex_unlock(&philo->mutex);
			pthread_mutex_unlock(&philo->info->somebody_dead);
			return ((void *)0);
		}
		pthread_mutex_unlock(&philo->mutex);
		usleep(1000);
		// ft_sleep(1);
	}
	return ((void *)0);
}

void	*monitor_count(void *in)
{
	t_info	*info;
	int		i;
	int		total;

	info = (t_info *)in;
	total = 0;
	while (total < info->ntime_eat)
	{
		i = 0;
		while (i < info->num_philo)
			pthread_mutex_lock(&info->philos[i++].eat_m);
		total++;
	}
	print_msg(&info->philos[0], T_OVER);
	pthread_mutex_unlock(&info->somebody_dead);
	return ((void *)0);
}

static int	start_threads(t_info *info)
{
	int			i;
	pthread_t	tid;
	void		*philo;

	info->start = get_time();
	if (info->ntime_eat > 0)
	{
		if (pthread_create(&tid, NULL, &monitor_count, (void *)info) != 0)
			return (1);
		pthread_detach(tid);
	}
	i = 0;
	while (i < info->num_philo)
	{
		philo = (void *)(&info->philos[i]);
		if (pthread_create(&tid, NULL, &routine, philo) != 0)
			return (1);
		pthread_detach(tid);
		usleep(100);
		// ft_sleep(1000);
		i++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_info	info;

	if (argc < 5 || argc > 6)
	{
		printf("argument error\n");
		return (0);
	}
	// if (argc == 6)
	// 	printf("number of times each philosopher must eat: %s\n", argv[5]);
	if (!init_info(&info, argc, argv))
		return (write(2, "argument error\n", 16) && clear_info(&info));
	if (start_threads(&info))
		return (clear_info(&info) && write(2, "error\n", 7));
	pthread_mutex_lock(&info.somebody_dead);
	pthread_mutex_unlock(&info.somebody_dead);
	// write(1, "clear\n", 6);
	clear_info(&info);
	return (0);
}
