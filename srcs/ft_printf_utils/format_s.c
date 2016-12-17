/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 14:49:28 by ofedorov          #+#    #+#             */
/*   Updated: 2016/11/01 14:49:29 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

static int	wchars_in_len(wchar_t *str, int len)
{
	int	n;

	n = 0;
	while (str && *str && n + ft_wcharlen(*str) <= len)
	{
		n += ft_wcharlen(*str);
		str++;
	}
	return (n);
}

static int	do_s(void *str, t_flags *flags)
{
	int	written;

	written = 0;
	if (flags->just_count)
	{
		if (flags->length_mod == LEN_NONE)
			flags->chars_val = (flags->precision >= 0) ? MIN(flags->precision,
				(int)ft_strlen(str)) : ft_strlen((char*)str);
		else
			flags->chars_val = (flags->precision >= 0) ? MIN(flags->precision,
			wchars_in_len(str, flags->precision)) : ft_wstrlen((wchar_t*)str);
	}
	else
	{
		if (flags->precision != -1)
			written = (flags->length_mod == LEN_NONE)
					? ft_putnstr_fd(str, flags->fd, flags->precision)
					: ft_putnwstr_fd(str, flags->fd, flags->precision);
		else
			written = (flags->length_mod == LEN_NONE)
			? ft_putstr_fd(str, flags->fd) : ft_putwstr_fd(str, flags->fd);
		flags->chars_wr += written;
	}
	(written < 0) ? flags->error = "can't write to the file descriptor" : (0);
	return (flags->error) ? -1 : flags->chars_wr;
}

static void	*get_value(t_flags *flags, va_list ap)
{
	if (flags->length_mod == LEN_L)
		return (va_arg(ap, wchar_t*));
	if (flags->length_mod == LEN_NONE)
		return (va_arg(ap, char*));
	return (NULL);
}

int			format_s(t_flags *flags, va_list ap)
{
	void	*val;

	val = get_value(flags, ap);
	flags->just_count = true;
	if (val == NULL)
		flags->chars_val = (flags->precision >= 0 && flags->precision <= 6) ?
				flags->precision : 6;
	else
		do_s(val, flags);
	flags->just_count = false;
	format_before(flags);
	if (val == NULL)
		ft_printf_write("(null)",
						(flags->precision >= 0 && flags->precision < 6) ?
						flags->precision : 6, flags);
	else
		do_s(val, flags);
	format_after(flags);
	return (flags->chars_wr);
}
