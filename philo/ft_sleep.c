/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahnys <ahnys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 17:36:23 by ahnys             #+#    #+#             */
/*   Updated: 2021/08/14 20:13:59 by ahnys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
