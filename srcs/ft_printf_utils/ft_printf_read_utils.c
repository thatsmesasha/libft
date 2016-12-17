/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_read_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 11:20:50 by ofedorov          #+#    #+#             */
/*   Updated: 2016/12/05 11:20:52 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

void	assign_false(int number, ...)
{
	va_list	ap;
	bool	*param;

	va_start(ap, number);
	while (number-- > 0)
	{
		param = va_arg(ap, bool*);
		*param = false;
	}
}

int		is_flag(char c)
{
	if (c == '+' || c == '-' || c == ' ' || c == '#' || c == '0')
		return (1);
	return (0);
}

int		is_len_mod(char c)
{
	if (c == 'h' || c == 'l' || c == 'j' || c == 'z' || c == 't' || c == 'L')
		return (1);
	return (0);
}

int		is_format(char c)
{
	if (c == 'c' || c == 's' || c == 'd' || c == 'i' || c == 'o' || c == 'x' ||
		c == 'u' || c == 'f' || c == 'e' || c == 'a' || c == 'g' || c == 'n' ||
		c == 'p' || c == 'X' || c == 'F' || c == 'E' || c == 'A' || c == 'G' ||
		c == 'C' || c == 'S' || c == 'D' || c == 'O' || c == 'U')
		return (1);
	return (0);
}
