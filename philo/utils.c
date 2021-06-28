#include "philo.h"

/*
** micro seconds : 1 / 1,000,000
** milli seconds : 1 / 1,000
** timeval { time_t tv_sec; (seconds)
**			suseconds_t tv_usec; (microseconds)}
*/
int		get_time(void)
{
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

int		mutex_init(t_info *info)
{
	int		i;

	if (!(info->forks = malloc(sizeof(pthread_mutex_t) * info->num_philo)))
		return (0);
	i = 0;
	while (i < info->num_philo)
		pthread_mutex_init(&(info->forks[i++]), NULL);
	return (1);
}

int		init_info(t_info *info, int argc, char *argv[])
{
	info->num_philo = ft_atoi(argv[1]);
	info->t_die = ft_atoi(argv[2]);
	info->t_eat = ft_atoi(argv[3]);
	info->t_sleep = ft_atoi(argv[4]);
	info->ntime_eat = -1;
	if (argc == 6)
		info->ntime_eat = ft_atoi(argv[5]);
	//philo init
	return (mutex_init(info));
}