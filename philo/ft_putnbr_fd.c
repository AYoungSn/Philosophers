/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahnys <ahnys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 21:39:57 by ahnys             #+#    #+#             */
/*   Updated: 2021/07/30 21:42:31 by ahnys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	mod;

	mod = n % 10;
	n /= 10;
	if (n != 0)
		ft_putnbr_fd(n, fd);
	if (mod < 0)
	{
		if (n == 0)
			write(fd, "-", 1);
		mod = -mod + '0';
		write(fd, &mod, 1);
	}
	else
	{
		mod += '0';
		write(fd, &mod, 1);
	}
	return ;
}
