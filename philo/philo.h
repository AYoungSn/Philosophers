/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahnys <ahnys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 21:40:34 by ahnys             #+#    #+#             */
/*   Updated: 2021/07/30 21:53:02 by ahnys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <string.h>

# define T_FORK_L 0
# define T_FORK 1
# define T_EAT 2
# define T_SLP 3
# define T_THINK 4
# define T_DIE 5
# define T_OVER 6

typedef struct s_philo
{
	int				position;
	int				lfork;
	int				rfork;
	int				is_eating;
	int				eat_count;
	struct s_info	*info;
	long long		last_eat;
	uint64_t		limit;
	pthread_mutex_t	mutex;
	pthread_mutex_t	eat_m;
}					t_philo;

typedef struct s_info
{
	int				num_philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	wri;
	pthread_mutex_t	somebody_dead;
	t_philo			*philos;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				ntime_eat;
	long long		start;
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
uint64_t			get_time(void);
int					init_info(t_info *info, int argc, char *argv[]);

/*
** routine.c
*/
void				*routine(void *p);
void				take_forks(t_philo *philo);
void				philo_eat(t_philo *philo);
void				philo_sleep(t_philo *philo);

void				print_msg(t_philo *philo, int type);
int					clear_info(t_info *info);

#endif
