/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnwstr_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 16:25:34 by ofedorov          #+#    #+#             */
/*   Updated: 2016/12/17 12:57:12 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_putnwstr_fd(wchar_t const *str, int fd, int length)
{
	int i;
	int	ret;

	i = 0;
	while (str && *str && i != -1 && i + ft_wcharlen(*str) <= length)
	{
		ret = ft_putwchar_fd(*str++, fd);
		i = (ret != -1) ? i + ret : -1;
	}
	return (str == NULL) ? -1 : i;
}
