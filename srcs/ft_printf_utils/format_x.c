/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 14:49:52 by ofedorov          #+#    #+#             */
/*   Updated: 2016/11/01 14:49:53 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

static int	do_x(unsigned long long nbr, t_flags *flags)
{
	short				len;
	unsigned long long	val;
	char				c;
	char				*hex;

	hex = "0123456789abcdef";
	val = nbr;
	len = 1;
	while (val >= 16)
	{
		val /= 16;
		len++;
	}
	while (len-- != 0)
	{
		c = hex[(ABS((nbr / ft_power(16, len)) % 16))];
		ft_printf_write(&c, 1, flags);
	}
	return (flags->error) ? -1 : flags->chars_wr;
}

int			format_x(t_flags *flags, va_list ap)
{
	unsigned long long	val;
	int					precision;

	val = get_value_oxu(flags, ap);
	flags->just_count = true;
	do_x(val, flags);
	if (flags->precision == 0 && val == 0)
		flags->chars_val = 0;
	flags->just_count = false;
	format_before(flags);
	if (flags->alternative && val != 0)
		ft_printf_write("0x", 2, flags);
	precision = (flags->precision == -1) ? flags->field_width :
				flags->precision;
	if (flags->zero && flags->precision != -1)
		precision = flags->field_width;
	(flags->alternative && flags->precision == -1) ? precision -= 2 : (0);
	while (precision-- - flags->chars_val > 0 && (flags->precision > 0 ||
			flags->zero))
		ft_printf_write("0", 1, flags);
	if (flags->precision != 0 || val != 0)
		do_x(val, flags);
	format_after(flags);
	return (flags->chars_wr);
}
