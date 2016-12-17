/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 16:25:43 by ofedorov          #+#    #+#             */
/*   Updated: 2016/12/17 12:57:51 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_putnstr_fd(char const *str, int fd, int length)
{
	int i;

	i = 0;
	while (str && *str && i != -1 && length-- > 0)
		i = (ft_putchar_fd(*str++, fd) == 1) ? i + 1 : -1;
	return (str == NULL) ? -1 : i;
}
