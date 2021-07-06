#include "philo.h"

void	*monitor(void *p)
{
	t_philo	*philo;

	philo = p;
	while (1)
	{
		pthread_mutex_lock(&philo->mutex);
		if (!philo->is_eating && get_time() > philo->limit)
		{
			print_msg(philo, T_DIE);
			pthread_mutex_unlock(&philo->mutex);
			return ((void*)0);
		}
		pthread_mutex_unlock(&philo->mutex);
		usleep(1000);
	}
	return ((void*)0);
}

void	*monitor_count(void *in)
{
	t_info	*info;

	info = (t_info*)in;
	return ((void*)0);
}

static int	start_threads(t_info *info)
{
	int	i;
	pthread_t tid;
	void	*philo;

	info->start = get_time();
	if (info->ntime_eat > 0)
	{
		// if (pthread_create(&tid, NULL, &monitor_count, (void*)info) != 0)
		// 	return (1);
		// pthread_detach(tid);
	}
	i = 0;
	while (i < info->num_philo)
	{
		philo = (void*)(&info->philos[i]);
		if (pthread_create(&tid, NULL, &routine, philo) != 0)
			return (1);
		pthread_detach(tid);
		i++;
	}
	return (0);
}

int		main(int argc, char *argv[])
{
	t_info	info;

	if (argc < 5 || argc > 6)
	{
		printf("argument error\n");
		return (0);
	}
	printf("number of philosophers: %s\n", argv[1]);
	printf("time to die: %s\n", argv[2]);
	printf("time to eat: %s\n", argv[3]);
	printf("time to sleep: %s\n", argv[4]);
	if (argc == 6)
		printf("number of times each philosopher must eat: %s\n", argv[5]);
	if (!init_info(&info, argc, argv))
		return write(2, "argument error\n", 16);
	if (start_threads(&info))
		return (1);
	printf("%d\n", get_time());
	return (0);
}