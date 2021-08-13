#include "philo.h"

void	ft_sleep(useconds_t time)
{
	uint64_t	start;

	start = get_time();
	while (get_time() - start < time)
	{
		usleep(1000);
	}
}