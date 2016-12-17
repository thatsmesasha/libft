/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 10:27:02 by ofedorov          #+#    #+#             */
/*   Updated: 2016/12/17 12:49:38 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

long long		ft_power(int base, int power)
{
	long long	nbr;

	nbr = 1;
	if (power < 0)
		return (0);
	while (power-- > 0)
		nbr *= base;
	return (nbr);
}
