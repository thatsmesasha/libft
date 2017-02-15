/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 18:26:27 by ofedorov          #+#    #+#             */
/*   Updated: 2017/02/05 18:26:28 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t size)
{
	size_t	index;
	char	*copy;

	copy = (char *)malloc(sizeof(char) * (size + 1));
	if (copy == NULL)
		return (NULL);
	index = 0;
	while (index < size && s[index] != '\0')
	{
		copy[index] = s[index];
		index++;
	}
	copy[size] = '\0';
	return (copy);
}
