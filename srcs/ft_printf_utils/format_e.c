/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_e.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 14:48:44 by ofedorov          #+#    #+#             */
/*   Updated: 2016/11/01 14:48:46 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

const char	g_dec[11] = "0123456789";

static int	get_power(long double *nbr)
{
	int i;

	i = 0;
	if (*nbr >= 10)
		while ((*nbr) >= 10)
		{
			i++;
			*nbr /= 10;
		}
	else if (0 < *nbr && *nbr < 1)
		while (*nbr < 1)
		{
			i--;
			*nbr *= 10;
		}
	return (i);
}

static int	round(long double *nbr, t_flags *flags)
{
	int			precision;
	int			round_top;
	long double	left;

	*nbr = ABS(*nbr);
	round_top = 0;
	precision = flags->precision;
	left = *nbr - (long long)*nbr;
	while (precision-- > 0)
		left = 10 * left - (int)(left * 10);
	if (left > 0.5)
	{
		left = -1;
		round_top = 1;
	}
	precision = flags->precision;
	while (precision-- > 0)
		left = left / 10;
	if (round_top)
		*nbr = *nbr - left;
	return (0);
}

static int	do_e(long double nbr, t_flags *flags)
{
	int power;
	int left;

	round(&nbr, flags);
	(flags->precision == -1) ? flags->precision = 6 : (0);
	left = flags->precision;
	power = get_power(&nbr);
	ft_printf_write(&g_dec[(int)nbr], 1, flags);
	if (left != 0 || flags->alternative)
		ft_printf_write(".", 1, flags);
	while (left-- != 0)
	{
		nbr = (nbr - (int)nbr) * 10;
		ft_printf_write(&g_dec[(int)nbr], 1, flags);
	}
	ft_printf_write("e", 1, flags);
	ft_putpower(power, flags, 2);
	return (flags->chars_wr);
}

int			format_e(t_flags *flags, va_list ap)
{
	long double	val;

	val = get_value_feag(flags, ap);
	flags->just_count = true;
	if (is_nan(val) || is_inf(val))
	{
		flags->chars_val = 3;
		flags->space = is_nan(val) ? false : flags->space;
	}
	else
		do_e(val, flags);
	flags->just_count = false;
	flags->positive = (val < 0) ? false : true;
	format_before(flags);
	if (is_nan(val) || is_inf(val))
		ft_printf_write(is_nan(val) ? "nan" : "inf", 3, flags);
	else
		flags->chars_wr = do_e(val, flags);
	format_after(flags);
	return (flags->chars_wr);
}
