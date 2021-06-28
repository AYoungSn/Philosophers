#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <string.h>

typedef struct		s_philo
{
	int				num;
	int				start;
}					t_philo;

typedef struct		s_info
{
	int				num_philo;
	pthread_mutex_t	*forks;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				ntime_eat;
}					t_info;

void				philo_start(void);
void				philo_eat();
void				philo_think();
void				philo_sleep();
/*
** die check
*/
void				monitoring();

int					ft_atoi(char *str);
/*
** utils.c
*/
int					get_time(void);
int					init_info(t_info *info, int argc, char *argv[]);

#endif
