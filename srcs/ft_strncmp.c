/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 21:55:00 by ofedorov          #+#    #+#             */
/*   Updated: 2016/09/27 12:47:16 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (n-- > 0 && *s1 != '\0' && *s1 == *s2)
	{
		if (n != 0)
		{
			s1++;
			s2++;
		}
	}
	return ((unsigned char)(*s1) - (unsigned char)(*s2));
}
