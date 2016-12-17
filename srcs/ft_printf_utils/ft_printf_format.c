/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 17:22:19 by ofedorov          #+#    #+#             */
/*   Updated: 2016/11/12 17:22:21 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

#define IS_DIOUX(c) (c == 'd' || c == 'i' || c == 'o' || c == 'u' || c == 'x')

int		supported_format(char c)
{
	if (c == 'c' || c == 's' || c == 'd' || c == 'i' || c == 'o' ||
		c == 'x' || c == 'u' || c == 'f' || c == 'e' || c == 'a' ||
		c == 'g' || c == 'n' || c == 'p')
		return (1);
	return (0);
}

t_flags	*new_flags(int fd, char format, bool just_count)
{
	t_flags	*flags;

	flags = (t_flags*)malloc(sizeof(t_flags));
	flags->fd = fd;
	flags->format = format;
	flags->length_mod = LEN_NONE;
	flags->just_count = just_count;
	flags->chars_wr = 0;
	flags->chars_val = 0;
	flags->error = NULL;
	flags->alternative = false;
	flags->capital = false;
	flags->field_width = -1;
	flags->left_justified = false;
	flags->precision = -1;
	flags->sign = false;
	flags->positive = true;
	flags->space = false;
	return (flags);
}

void	format_before(t_flags *flags)
{
	int	spaces;
	int	precision;

	spaces = flags->field_width - flags->chars_val;
	spaces -= (flags->sign || flags->space || !flags->positive) ? 1 : 0;
	spaces -= (flags->format == 'x' && flags->alternative ? 2 : 0);
	if (IS_DIOUX(flags->format) && (flags->precision > flags->chars_val))
		spaces -= flags->precision - flags->chars_val;
	if (!flags->left_justified && flags->field_width != -1 && !flags->zero)
		while (spaces-- > 0)
			ft_printf_write(" ", 1, flags);
	if ((flags->sign || flags->space) && flags->positive)
		ft_printf_write(flags->sign ? "+" : " ", 1, flags);
	(!flags->positive) ? ft_printf_write("-", 1, flags) : (0);
	((flags->sign || flags->space || !flags->positive) &&
	!flags->left_justified && flags->field_width != -1)
	? flags->field_width-- : 0;
	precision = flags->precision == -1 ? flags->field_width : flags->precision;
	if (!IS_DIOUX(flags->format))
		precision = flags->field_width;
	if (precision != 0 && ((flags->zero && flags->format != 'x') ||
		((flags->format == 'd' || flags->format == 'i' || flags->format == 'o'
		|| flags->format == 'u') && flags->precision != -1)))
		while (precision-- - flags->chars_val > 0)
			ft_printf_write("0", 1, flags);
}

void	format_after(t_flags *flags)
{
	if (flags->error || flags->chars_wr == -1)
		flags->chars_wr = -1;
	else if (flags->left_justified && flags->field_width != -1)
		while (flags->chars_wr < flags->field_width && !flags->error)
			ft_printf_write(" ", 1, flags);
}

int		switch_format(t_flags *flags, va_list ap, int ch_wr)
{
	int	wr;

	wr = 1;
	if (supported_format(flags->format))
		return (g_formats[(int)flags->format](flags, ap));
	if (flags->format == 'n')
	{
		ft_putnbr_fd(ch_wr, flags->fd);
		while (ch_wr >= 10)
		{
			ch_wr /= 10;
			wr++;
		}
		return (wr);
	}
	else
		return (g_formats[(int)'?'](flags, ap));
}
