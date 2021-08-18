/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahnys <ahnys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 21:40:29 by ahnys             #+#    #+#             */
/*   Updated: 2021/08/18 14:12:38 by ahnys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitor(void *p)
{
	t_philo	*philo;

	philo = p;
	while (!philo->info->isDead)
	{
		pthread_mutex_lock(&philo->mutex);
		if (!philo->is_eating
			&& get_time() - philo->info->start > philo->limit)
		{
			print_msg(philo, T_DIE);
			pthread_mutex_unlock(&philo->mutex);
			pthread_mutex_unlock(&philo->info->somebody_dead);
			philo->info->isDead = 1;
			return ((void *)0);
		}
		pthread_mutex_unlock(&philo->mutex);
		usleep(200);
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
		info->philos[i].tid = tid;
		usleep(50);
		i++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_info	info;

	if (argu_check(&info, argc, argv))
	{
		write(2, "argument error\n", 16);
		return (0);
	}
	if (info.ntime_eat == 0)
	{
		write(1, "0ms must eat count reached\n", 28);
		return (0);
	}
	if (!init_info(&info))
		return (write(2, "argument error\n", 16) && clear_info(&info));
	if (start_threads(&info))
		return (clear_info(&info) && write(2, "error\n", 7));
	pthread_mutex_lock(&info.somebody_dead);
	pthread_mutex_unlock(&info.somebody_dead);
	clear_info(&info);
	return (0);
}
