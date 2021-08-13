#include "philo.h"

void	ft_sleep(useconds_t time)
{
	uint64_t	purpose;

	purpose = get_time() + time;
	while (get_time() < purpose)
	{
		if (get_time() >= purpose)
			break ;
		usleep(100);
	}
}