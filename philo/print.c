#include "philo.h"

void	print_msg(t_philo *philo, int type)
{
	pthread_mutex_lock(&philo->info->wri);
	ft_putnbr_fd(get_time() - philo->info->start, 1);
	write(1, " ", 1);
	ft_putnbr_fd(philo->position + 1, 1);
	if (type == T_FORK)
		write(1, " has taken a fork\n", 19);
	else if (type == T_EAT)
		write(1, " is eating\n", 12);
	else if (type == T_SLP)
		write(1, " is sleeping\n", 14);
	else if (type == T_THINK)
		write(1, " is thinking\n", 14);
	else if (type == T_DIE)
		write(1, " died\n", 7);
	pthread_mutex_unlock(&philo->info->wri);
}