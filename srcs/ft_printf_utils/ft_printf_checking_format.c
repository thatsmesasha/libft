/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_checking_format.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 11:01:13 by ofedorov          #+#    #+#             */
/*   Updated: 2016/12/05 11:01:16 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

unsigned char g_cs[9] = {0, 0, 1, 1, 0, 0, 0, 0, 0};
unsigned char g_dioxun[9] = {1, 1, 1, 1, 1, 1, 1, 1, 0};
unsigned char g_feag[9] = {0, 0, 1, 1, 0, 0, 0, 0, 1};
unsigned char g_pcs_perc[9] = {0, 0, 1, 0, 0, 0, 0, 0, 0};

void	check_length_mod(t_flags *flags, const char **format)
{
	if (**format == 'h' && *(*format + 1) == 'h')
		flags->length_mod = (flags->length_mod == LEN_NONE) ? LEN_HH :
							MAX(LEN_HH, flags->length_mod);
	else if (**format == 'h')
		flags->length_mod = (flags->length_mod == LEN_NONE) ? LEN_H : MAX(LEN_H,
														flags->length_mod);
	else if (**format == 'l' && *(*format + 1) == 'l')
		flags->length_mod = MAX(LEN_LL, flags->length_mod);
	else if (**format == 'l')
		flags->length_mod = MAX(LEN_L, flags->length_mod);
	else if (**format == 'j')
		flags->length_mod = MAX(LEN_J, flags->length_mod);
	else if (**format == 'z')
		flags->length_mod = MAX(LEN_Z, flags->length_mod);
	else if (**format == 't')
		flags->length_mod = MAX(LEN_T, flags->length_mod);
	else if (**format == 'L')
		flags->length_mod = MAX(LEN_L_CAP, flags->length_mod);
	else
		return ;
	if (flags->length_mod != LEN_NONE)
		(*format)++;
	if (flags->length_mod == LEN_HH || flags->length_mod == LEN_LL)
		(*format)++;
}

void	check_field_width_dig(t_flags *flags, const char **format)
{
	flags->field_width = ft_atoi(*format);
	while (ft_isdigit(**format))
		(*format)++;
	if (flags->field_width < 0)
	{
		flags->left_justified = true;
		flags->zero = false;
		flags->field_width = -(flags->field_width);
	}
}

void	check_field_width_star(t_flags *flags, const char **format, va_list ap)
{
	flags->field_width = va_arg(ap, int);
	(*format)++;
	if (flags->field_width < 0)
	{
		flags->left_justified = true;
		flags->zero = false;
		flags->field_width = -(flags->field_width);
	}
}

void	check_l_mod(t_flags *flags)
{
	int ret;

	ret = 2;
	if (flags->format == 'c' || flags->format == 's')
		ret = g_cs[flags->length_mod];
	if (flags->format == 'd' || flags->format == 'i' || flags->format == 'o' ||
		flags->format == 'x' || flags->format == 'u' || flags->format == 'n')
		ret = g_dioxun[flags->length_mod];
	if (flags->format == 'f' || flags->format == 'e' || flags->format == 'a' ||
		flags->format == 'g')
		ret = g_feag[flags->length_mod];
	if (flags->format == 'p' || flags->format == '%')
		ret = g_pcs_perc[flags->length_mod];
	if (ret == 0)
		flags->length_mod = LEN_NONE;
}

void	check_specific_f(t_flags *flags)
{
	(flags->format == 'c') ? assign_false(3,
						&flags->sign, &flags->space, &flags->alternative) : 0;
	(flags->format == 's') ? assign_false(3, &flags->sign, &flags->space,
						&flags->alternative) : 0;
	(flags->format == 'd' || flags->format == 'i') ? assign_false(1,
						&flags->alternative) : 0;
	(flags->format == 'o' || flags->format == 'x' || flags->format == 'u') ?
						assign_false(2, &flags->sign, &flags->space) : 0;
	(flags->format == 'u') ? assign_false(1, &flags->alternative) : 0;
	(flags->format == 'n') ? assign_false(5, &flags->alternative, &flags->sign,
					&flags->space, &flags->zero, &flags->left_justified) : 0;
	(flags->format == 'n') ? flags->field_width = -1 : 0;
	if (flags->format == 'p' && flags->zero && flags->precision == -1)
		flags->precision = (flags->field_width >= 2) ? flags->field_width - 2 :
							flags->precision;
	(flags->format == 'p') ? assign_false(4, &flags->sign, &flags->zero,
		&flags->space, &flags->alternative) : 0;
	if (!supported_format(flags->format))
		assign_false(2, &flags->space, &flags->sign);
	if ((flags->format == 'd' || flags->format == 'i' || flags->format == 'x' ||
		flags->format == 'u' || flags->format == 'o') && flags->precision != -1)
		assign_false(1, &flags->zero);
}
