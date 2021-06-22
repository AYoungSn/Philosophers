#include "philo.h"

int		main(int argc, char *argv[])
{
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
	return (0);
}
