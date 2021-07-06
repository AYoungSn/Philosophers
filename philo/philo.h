#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <string.h>

# define T_FORK 1
# define T_EAT 2
# define T_SLP 3
# define T_THINK 4
# define T_DIE 5
# define T_OVER 6

typedef struct		s_philo
{
	int				position;
	int				lfork;
	int				rfork;
	int				is_eating;
	int				eat_count;
	struct s_info	*info;
	long			last_eat;
	long			limit;
	pthread_mutex_t	mutex;
}					t_philo;

typedef struct		s_info
{
	int				num_philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t wri;
	t_philo			*philos;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				ntime_eat;
	long			start;
}					t_info;

/*
** philo.c
*/
void				*monitor(void *p);
void				*monitor_count(void *in);

int					ft_atoi(char *str);
void				ft_putnbr_fd(int n, int fd);
/*
** utils.c
*/
int					get_time(void);
int					init_info(t_info *info, int argc, char *argv[]);

/*
** routine.c
*/
void				*routine(void *p);
void				take_forks(t_philo *philo);
void				philo_eat(t_philo *philo);
void				philo_sleep(t_philo *philo);

void				print_msg(t_philo *philo, int type);

#endif
