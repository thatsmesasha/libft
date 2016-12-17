/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 14:34:34 by ofedorov          #+#    #+#             */
/*   Updated: 2016/12/17 12:50:38 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_putwchar_fd(wchar_t c, int fd)
{
	if (c <= 0x7F)
		return (ft_putchar_fd(c, fd) == -1) ? -1 : 1;
	else if (c <= 0x7FF)
	{
		return (ft_putchar_fd((c >> 6) + 0xC0, fd) == -1 ||
				ft_putchar_fd((c & 0x3F) + 0x80, fd) == -1) ? -1 : 2;
	}
	else if (c <= 0xFFFF)
	{
		return (ft_putchar_fd((c >> 12) + 0xE0, fd) == -1 ||
				ft_putchar_fd(((c >> 6) & 0x3F) + 0x80, fd) == -1 ||
				ft_putchar_fd((c & 0x3F) + 0x80, fd) == -1) ? -1 : 3;
	}
	else if (c <= 0x10FFFF)
	{
		return (ft_putchar_fd((c >> 18) + 0xF0, fd) == -1 ||
				ft_putchar_fd(((c >> 12) & 0x3F) + 0x80, fd) == -1 ||
				ft_putchar_fd(((c >> 6) & 0x3f) + 0x80, fd) == -1 ||
				ft_putchar_fd((c & 0x3F) + 0x80, fd) == -1) ? -1 : 4;
	}
	return (-1);
}
