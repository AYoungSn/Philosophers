#include "philo.h"

void	*routine(void *p)
{
	t_philo	*philo;
	pthread_t	tid;

	philo = (t_philo*)p;
	if (pthread_create(&tid, NULL, &monitor, philo) != 0)
		return ((void*)1);
	pthread_detach(tid);
	while (1)
	{
		take_forks(philo);
		philo_eat(philo);
		philo_sleep(philo);
		print_msg(philo, T_THINK);
	}
}

void	take_forks(t_philo *philo)
{
	if (philo->position == 1)
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
	philo->is_eating = 1;
	philo->last_eat = get_time();
	philo->limit = philo->last_eat + philo->info->t_die + philo->info->t_eat;
	print_msg(philo, T_EAT);
	usleep(philo->info->t_eat * 1000);
	philo->eat_count++;
	philo->is_eating = 0;
}

void	philo_sleep(t_philo *philo)
{
	print_msg(philo, T_SLP);
	pthread_mutex_unlock(&philo->info->forks[philo->rfork]);
	pthread_mutex_unlock(&philo->info->forks[philo->lfork]);
	usleep(philo->info->t_sleep * 1000);
}
