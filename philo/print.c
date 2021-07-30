/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahnys <ahnys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 21:40:44 by ahnys             #+#    #+#             */
/*   Updated: 2021/07/30 21:49:05 by ahnys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_msg(t_philo *philo, int type)
{
	pthread_mutex_lock(&philo->info->wri);
	ft_putnbr_fd(get_time() - philo->info->start, 1);
	write(1, "ms ", 3);
	ft_putnbr_fd(philo->position + 1, 1);
	if (type == T_FORK_L)
		write(1, " has taken a left fork\n", 24);
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
