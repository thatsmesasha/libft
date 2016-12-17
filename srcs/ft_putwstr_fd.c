/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 16:11:01 by ofedorov          #+#    #+#             */
/*   Updated: 2016/12/17 12:56:23 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_putwstr_fd(wchar_t const *str, int fd)
{
	int i;
	int	ret;

	i = 0;
	while (str && *str && i != -1)
	{
		ret = ft_putwchar_fd(*str++, fd);
		i = (ret != -1) ? i + ret : -1;
	}
	return (str == NULL) ? -1 : i;
}
