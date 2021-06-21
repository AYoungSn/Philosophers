#include "philo.h"

static int	is_space(char ch)
{
	if (ch == '\n' || ch == '\v' || ch == '\f'
	|| ch == '\r' || ch == '\t' || ch == ' ')
		return (1);
	return (0);
}

static int	ft_isdigit(char ch)
{
	if (ch >= '0' && ch <= '9')
		return (1);
	return (0);
}

int			ft_atoi(char *str)
{
	int		minus;
	long	result;

	while (is_space(*str))
		str++;
	minus = 1;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			minus = -1;
	result = 0;
	while (ft_isdigit(*str))
	{
		result = result * 10 + (*str++ - '0');
		if (minus * result > 2147483647)
			return (-1);
		else if (minus * result < -2147483648)
			return (0);
	}
	return (minus * result);
}