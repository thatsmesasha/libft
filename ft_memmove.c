/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 13:47:47 by ofedorov          #+#    #+#             */
/*   Updated: 2016/09/24 12:44:34 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*cdst;
	const unsigned char	*csrc;

	if (len == 0)
		return (dst);
	cdst = (unsigned char *)dst;
	csrc = (const unsigned char *)src;
	i = 0;
	if (csrc <= cdst && (csrc + len) > cdst)
		while (len > 0)
		{
			len--;
			cdst[len] = csrc[len];
		}
	else
		while (i < len)
		{
			cdst[i] = csrc[i];
			i++;
		}
	return (dst);
}
