/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 14:50:11 by ofedorov          #+#    #+#             */
/*   Updated: 2016/11/01 14:50:12 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

static int	do_p(void *ptr, t_flags *flags)
{
	unsigned long long	val;
	int					len;
	char				c;
	char				*hex;

	hex = "0123456789abcdef";
	val = (unsigned long long)ptr;
	len = 1;
	while (val >= 16)
	{
		val /= 16;
		len++;
	}
	val = (unsigned long long)ptr;
	if (flags->precision > len)
		len = flags->precision;
	while (len-- > 0)
	{
		c = hex[(ABS((val / ft_power(16, len)) % 16))];
		ft_printf_write(&c, 1, flags);
	}
	return (flags->error) ? -1 : flags->chars_wr;
}

int			format_p(t_flags *flags, va_list ap)
{
	void				*val;
	int					precision;

	val = va_arg(ap, void *);
	flags->just_count = true;
	do_p(val, flags);
	if (flags->precision == 0 && val == 0)
		flags->chars_val = 0;
	flags->precision = ((flags->chars_val > flags->precision) && val != NULL)
						? -1 : flags->precision;
	flags->chars_val += 2;
	flags->just_count = false;
	format_before(flags);
	precision = flags->precision;
	ft_printf_write("0x", 2, flags);
	if (flags->zero || flags->precision != -1)
		while (precision-- - flags->chars_val > 0)
			ft_printf_write("0", 1, flags);
	if (flags->precision != 0 || val != 0)
		flags->chars_wr = do_p(val, flags);
	format_after(flags);
	return (flags->chars_wr);
}
