/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 13:13:34 by ofedorov          #+#    #+#             */
/*   Updated: 2016/09/26 20:18:47 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Min value -9223372036854775808
*/

static int	negnbr(const char *str)
{
	long long	number;

	number = 0;
	while (*str >= '0' && *str <= '9')
	{
		if (number < -922337203685477580 ||
			(number == -922337203685477580 && *str > '8'))
			return (0);
		number = number * 10 - (*str - '0');
		str++;
	}
	return ((int)number);
}

/*
**	Max value 9223372036854775807
*/

static int	posnbr(const char *str)
{
	long long	number;

	number = 0;
	while (*str >= '0' && *str <= '9')
	{
		if (number > 922337203685477580 ||
			(number == 922337203685477580 && *str > '7'))
			return (-1);
		number = number * 10 + (*str - '0');
		str++;
	}
	return ((int)number);
}

int			ft_atoi(const char *str)
{
	while (*str == '\t' || *str == '\v' || *str == ' ' ||
			*str == '\r' || *str == '\f' || *str == '\n')
		str++;
	if (*str == '-')
	{
		str++;
		return (negnbr(str));
	}
	if (*str == '+')
		str++;
	return (posnbr(str));
}
