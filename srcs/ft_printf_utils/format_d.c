/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 14:48:26 by ofedorov          #+#    #+#             */
/*   Updated: 2016/11/01 14:48:28 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

static int			do_d(ptrdiff_t nbr, t_flags *flags)
{
	short		len;
	ptrdiff_t	val;
	char		c;

	val = nbr;
	len = 1;
	while (val >= 10 || val <= -10)
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

static ptrdiff_t	get_value(t_flags *flags, va_list ap)
{
	if (flags->length_mod == LEN_T)
		return (ptrdiff_t)va_arg(ap, ptrdiff_t);
	if (flags->length_mod == LEN_Z)
		return (ptrdiff_t)va_arg(ap, ssize_t);
	if (flags->length_mod == LEN_J)
		return (ptrdiff_t)va_arg(ap, intmax_t);
	if (flags->length_mod == LEN_LL)
		return (ptrdiff_t)va_arg(ap, long long);
	if (flags->length_mod == LEN_L)
		return (ptrdiff_t)va_arg(ap, long);
	if (flags->length_mod == LEN_NONE)
		return (ptrdiff_t)va_arg(ap, int);
	if (flags->length_mod == LEN_H)
		return (ptrdiff_t)(short int)va_arg(ap, int);
	if (flags->length_mod == LEN_HH)
		return (ptrdiff_t)(char)va_arg(ap, int);
	return (0);
}

int					format_d(t_flags *flags, va_list ap)
{
	ptrdiff_t	val;

	val = get_value(flags, ap);
	flags->just_count = true;
	do_d(val, flags);
	if (flags->precision == 0 && val == 0)
		flags->chars_val = 0;
	flags->just_count = false;
	flags->positive = (val < 0) ? false : true;
	format_before(flags);
	if (flags->precision != 0 || val != 0)
		flags->chars_wr = do_d(val, flags);
	format_after(flags);
	return (flags->chars_wr);
}
