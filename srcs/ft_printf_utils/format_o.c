/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_o.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 14:49:16 by ofedorov          #+#    #+#             */
/*   Updated: 2016/11/01 14:49:18 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

static int	do_o(unsigned long long nbr, t_flags *flags)
{
	short				len;
	unsigned long long	val;
	char				c;
	char				*hex;

	hex = "0123456789abcdef";
	val = nbr;
	len = 1;
	while (val >= 8)
	{
		val /= 8;
		len++;
	}
	while (len-- != 0)
	{
		c = '0' + (ABS((nbr / ft_power(8, len)) % 8));
		ft_printf_write(&c, 1, flags);
	}
	return (flags->error) ? -1 : flags->chars_wr;
}

int			format_o(t_flags *flags, va_list ap)
{
	unsigned long long	val;

	val = get_value_oxu(flags, ap);
	flags->just_count = true;
	do_o(val, flags);
	if (flags->precision == 0 && val == 0 && !flags->alternative)
		flags->chars_val = 0;
	if (flags->alternative && val != 0 &&
			flags->precision <= flags->chars_val + 1)
		flags->chars_val++;
	flags->just_count = false;
	format_before(flags);
	if (flags->alternative && val != 0 &&
			flags->precision <= flags->chars_val + 1)
		ft_printf_write("0", 1, flags);
	if (flags->precision != 0 || val != 0 || flags->alternative)
		flags->chars_wr = do_o(val, flags);
	format_after(flags);
	return (flags->chars_wr);
}
