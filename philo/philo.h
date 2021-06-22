#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <string.h>

typedef struct	s_philo
{
	int			tid;
}				t_philo;

void			philo_eat();
void			philo_think();
void			philo_sleep();
void			monitoring();
int				ft_atoi(char *str);

#endif
