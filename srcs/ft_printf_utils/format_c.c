/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 14:47:59 by ofedorov          #+#    #+#             */
/*   Updated: 2016/11/01 14:48:00 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

static int		do_c(wint_t c, t_flags *flags)
{
	int	written;

	written = 0;
	if (flags->just_count)
	{
		flags->chars_val = ft_wcharlen(c);
		if (flags->length_mod == LEN_NONE)
			flags->chars_val = 1;
	}
	else
	{
		written = (flags->length_mod == LEN_NONE) ? ft_putchar_fd(c, flags->fd)
												: ft_putwchar_fd(c, flags->fd);
		if (flags->length_mod == LEN_NONE)
			written = 1;
		flags->error = (written < 0) ? "can't write to file descriptor" :
										flags->error;
		flags->chars_wr += written;
	}
	return (flags->error) ? -1 : flags->chars_wr;
}

static wint_t	get_value(t_flags *flags, va_list ap)
{
	if (flags->length_mod == LEN_L)
		return (va_arg(ap, wint_t));
	if (flags->length_mod == LEN_NONE)
		return (wint_t)va_arg(ap, int);
	return (0);
}

int				format_c(t_flags *flags, va_list ap)
{
	wint_t	val;

	val = get_value(flags, ap);
	flags->just_count = true;
	do_c(val, flags);
	flags->just_count = false;
	format_before(flags);
	flags->chars_wr = do_c(val, flags);
	format_after(flags);
	return (flags->chars_wr);
}
