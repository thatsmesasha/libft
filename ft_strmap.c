/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 15:21:06 by ofedorov          #+#    #+#             */
/*   Updated: 2016/09/27 11:29:16 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*result;
	size_t	i;

	if (!s)
		return (NULL);
	result = ft_strnew(ft_strlen(s));
	i = 0;
	while (result && s && s[i])
	{
		result[i] = f(s[i]);
		i++;
	}
	return (result);
}
