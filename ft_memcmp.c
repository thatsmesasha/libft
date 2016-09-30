/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 13:11:05 by ofedorov          #+#    #+#             */
/*   Updated: 2016/09/24 16:51:05 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char		*cs1;
	const unsigned char	*cs2;

	cs1 = (unsigned char *)s1;
	cs2 = (const unsigned char *)s2;
	if (n == 0)
		return (0);
	while (n-- > 0 && *cs1 == *cs2)
	{
		if (n != 0)
		{
			cs1++;
			cs2++;
		}
	}
	return (*cs1 - *cs2);
}
