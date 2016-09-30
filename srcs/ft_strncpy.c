/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 13:50:04 by ofedorov          #+#    #+#             */
/*   Updated: 2016/09/22 13:55:18 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*cdst;

	cdst = dst;
	while (len > 0 && *src != '\0')
	{
		*cdst++ = *src++;
		len--;
	}
	while (len > 0)
	{
		*cdst++ = '\0';
		len--;
	}
	return (dst);
}
