/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 10:08:21 by ofedorov          #+#    #+#             */
/*   Updated: 2016/12/05 12:21:57 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

static void	setup_formats(void)
{
	int	i;

	i = -1;
	while (++i < 128)
		g_formats[i] = NULL;
	g_formats['a'] = format_a;
	g_formats['c'] = format_c;
	g_formats['d'] = format_d;
	g_formats['c'] = format_c;
	g_formats['i'] = format_i;
	g_formats['e'] = format_e;
	g_formats['s'] = format_s;
	g_formats['o'] = format_o;
	g_formats['u'] = format_u;
	g_formats['x'] = format_x;
	g_formats['f'] = format_f;
	g_formats['p'] = format_p;
	g_formats['?'] = format_another;
}

int			ft_vprintf(const char *format, va_list ap)
{
	return (ft_vdprintf(1, format, ap));
}

int			ft_printf(const char *format, ...)
{
	va_list	ap;

	va_start(ap, format);
	return (ft_vprintf(format, ap));
}

int			ft_vdprintf(int fd, const char *format, va_list ap)
{
	int		chars_wr;
	t_flags	*flags;

	chars_wr = 0;
	setup_formats();
	if (!format)
		exit(11);
	while (*format)
	{
		if (*format == '%')
		{
			flags = read_format(fd, &format, ap);
			chars_wr += switch_format(flags, ap, chars_wr);
			if (flags->error)
				write(2, flags->error, ft_strlen(flags->error));
		}
		else
		{
			chars_wr += write(fd, format, 1);
		}
		if (*format)
			format++;
	}
	return (chars_wr);
}

int			ft_dprintf(int fd, const char *format, ...)
{
	va_list	ap;

	va_start(ap, format);
	return (ft_vdprintf(fd, format, ap));
}
