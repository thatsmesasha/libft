/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 15:33:22 by ofedorov          #+#    #+#             */
/*   Updated: 2016/09/27 16:04:11 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_abs(int n)
{
	return (n < 0) ? -n : n;
}

static char	*insert_nbr(char *number, int n, int length)
{
	int		i;

	i = 0;
	if (n < 0)
	{
		number[0] = '-';
		i = 1;
	}
	while (length-- > i)
	{
		number[length] = '0' + ft_abs(n - (n / 10) * 10);
		n /= 10;
	}
	return (number);
}

char		*ft_itoa(int n)
{
	int		length;
	char	*number;
	int		power_ten;

	length = 1;
	power_ten = 1;
	while (n / power_ten > 9 || n / power_ten < -9)
	{
		power_ten *= 10;
		length++;
	}
	if (n < 0)
		length++;
	number = ft_strnew(length);
	if (!number)
		return (NULL);
	return (insert_nbr(number, n, length));
}
