/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 15:51:35 by ofedorov          #+#    #+#             */
/*   Updated: 2016/12/04 15:51:36 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

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

static int	do_f(long double nbr, t_flags *flags)
{
	int		left;
	int		power;
	char	c;

	(flags->precision == -1) ? flags->precision = 6 : (0);
	left = flags->precision;
	round(&nbr, flags);
	power = 0;
	(nbr < 1 && nbr > -1) ? ft_printf_write("0", 1, flags) : (0);
	while (ABS(nbr) >= ft_power(10, power))
		power++;
	while (power-- > 0)
	{
		c = '0' + (long long)(nbr / ft_power(10, power)) % 10;
		ft_printf_write(&c, 1, flags);
	}
	if (left != 0 || flags->alternative)
		ft_printf_write(".", 1, flags);
	while (left-- != 0)
	{
		nbr = (nbr - (long long)nbr) * 10;
		c = '0' + (int)nbr;
		ft_printf_write(&c, 1, flags);
	}
	return (flags->chars_wr);
}

int			format_f(t_flags *flags, va_list ap)
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
		do_f(val, flags);
	flags->just_count = false;
	flags->positive = (val < 0) ? false : true;
	format_before(flags);
	if (is_nan(val) || is_inf(val))
		ft_printf_write(is_nan(val) ? "nan" : "inf", 3, flags);
	else
		flags->chars_wr = do_f(val, flags);
	format_after(flags);
	return (flags->chars_wr);
}
