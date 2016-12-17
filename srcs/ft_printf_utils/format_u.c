/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 14:49:40 by ofedorov          #+#    #+#             */
/*   Updated: 2016/11/01 14:49:41 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

static int	do_u(unsigned long long nbr, t_flags *flags)
{
	short				len;
	unsigned long long	val;
	char				c;

	val = nbr;
	len = 1;
	while (val >= 10)
	{
		val /= 10;
		len++;
	}
	while (len-- != 0)
	{
		c = '0' + (ABS((nbr / ft_power(10, len)) % 10));
		ft_printf_write(&c, 1, flags);
	}
	return (flags->error) ? -1 : flags->chars_wr;
}

int			format_u(t_flags *flags, va_list ap)
{
	unsigned long long	val;

	val = get_value_oxu(flags, ap);
	flags->just_count = true;
	do_u(val, flags);
	flags->just_count = false;
	if (flags->precision == 0 && val == 0)
		flags->chars_val = 0;
	format_before(flags);
	if (flags->precision != 0 || val != 0)
		do_u(val, flags);
	format_after(flags);
	return (flags->chars_wr);
}
