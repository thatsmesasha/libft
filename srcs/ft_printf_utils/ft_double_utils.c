/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 10:14:10 by ofedorov          #+#    #+#             */
/*   Updated: 2016/12/05 10:14:11 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

int	is_nan(long double nbr)
{
	return (nbr == nbr) ? 0 : 1;
}

int	is_inf(long double nbr)
{
	if (nbr > LDBL_MAX)
		return (1);
	if (nbr < -LDBL_MAX)
		return (-1);
	return (0);
}
