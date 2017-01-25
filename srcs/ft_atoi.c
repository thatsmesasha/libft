/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 13:13:34 by ofedorov          #+#    #+#             */
/*   Updated: 2016/12/17 14:34:51 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <limits.h>

static long long	negnbr(const char *str)
{
	long long	number;

	number = 0;
	while (ft_isdigit(*str))
	{
		if (number >= 0 ||
			(number == (LONG_MIN / 10) * 10 && *str > '8'))
			return (0);
		number = number * 10 - (*str - '0');
		str++;
	}
	return (number);
}

static long long	posnbr(const char *str)
{
	long long	number;

	number = 0;
	while (*str >= '0' && *str <= '9')
	{
		if (number < 0 ||
			(number == (LONG_MAX / 10) * 10  && *str > '7'))
			return (-1);
		number = number * 10 + (*str - '0');
		str++;
	}
	return (number);
}

long long			ft_atoi(const char *str)
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
