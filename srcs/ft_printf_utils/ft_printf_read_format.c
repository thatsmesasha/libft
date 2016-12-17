/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_read_format.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 22:45:20 by ofedorov          #+#    #+#             */
/*   Updated: 2016/11/12 22:45:24 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

void		check_flags(t_flags *flags, const char **format)
{
	while (**format == '-' || **format == '+' || **format == ' ' ||
			**format == '#' || **format == '0')
	{
		if (**format == '-')
			flags->left_justified = true;
		else if (**format == '+')
			flags->sign = true;
		else if (**format == ' ')
			flags->space = true;
		else if (**format == '#')
			flags->alternative = true;
		else if (**format == '0')
			flags->zero = true;
		(*format)++;
	}
	if (flags->space && flags->sign)
		flags->space = false;
	if (flags->zero && flags->left_justified)
		flags->zero = false;
}

void		check_precision(t_flags *flags, const char **format, va_list ap)
{
	if (**format == '.')
	{
		(*format)++;
		if (**format == '*')
		{
			flags->precision = va_arg(ap, int);
			if (flags->precision < 0)
				flags->precision = -1;
			(*format)++;
		}
		else if (ft_isdigit(**format))
		{
			flags->precision = ft_atoi(*format);
			while (ft_isdigit(**format))
				(*format)++;
		}
		else
			flags->precision = 0;
	}
}

void		determine_format(t_flags *flags, const char **f)
{
	if (**f == 'c' || **f == 's' || **f == 'd' || **f == 'i' || **f == 'o' ||
		**f == 'x' || **f == 'u' || **f == 'f' || **f == 'e' || **f == 'a' ||
		**f == 'g' || **f == 'n' || **f == 'p')
		flags->format = **f;
	else if (**f == 'X' || **f == 'F' || **f == 'E' || **f == 'A' || **f == 'G')
	{
		flags->format = **f - ('A' - 'a');
		flags->capital = true;
	}
	else if (**f == 'C' || **f == 'S' || **f == 'D' || **f == 'O' || **f == 'U')
	{
		flags->format = **f - ('A' - 'a');
		flags->length_mod = LEN_L;
	}
	else
		flags->format = **f;
}

t_flags		*read_format(int fd, const char **str, va_list ap)
{
	t_flags	*flags;

	flags = new_flags(fd, 0, false);
	(*str)++;
	while (!is_format(**str))
	{
		if (is_flag(**str))
			check_flags(flags, str);
		else if (ft_isdigit(**str))
			check_field_width_dig(flags, str);
		else if (**str == '*')
			check_field_width_star(flags, str, ap);
		else if (**str == '.')
			check_precision(flags, str, ap);
		else if (is_len_mod(**str))
			check_length_mod(flags, str);
		else
			break ;
	}
	determine_format(flags, str);
	check_l_mod(flags);
	check_specific_f(flags);
	return (flags);
}
