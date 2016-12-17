/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 14:47:38 by ofedorov          #+#    #+#             */
/*   Updated: 2016/11/01 14:47:41 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

static int	get_power(long double *nbr)
{
	int i;

	i = 0;
	*nbr = ABS(*nbr);
	if (*nbr > 1)
		while ((*nbr) >= 2)
		{
			i++;
			*nbr /= 2;
		}
	else if (0 < *nbr && *nbr < 1)
		while (*nbr < 1)
		{
			i--;
			*nbr *= 2;
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
		left = 16 * left - (int)(left * 16);
	if (left > 0.5)
	{
		left = -1;
		round_top = 1;
	}
	precision = flags->precision;
	while (precision-- > 0)
		left = left / 16;
	if (round_top)
		*nbr = *nbr - left;
	return (0);
}

int			ft_putpower(int power, t_flags *flags, int min_digits)
{
	short		len;
	int			val;
	char		c;

	val = power;
	len = 1;
	ft_printf_write(power < 0 ? "-" : "+", 1, flags);
	while (val >= 10 || val <= -10)
	{
		val /= 10;
		len++;
	}
	while (len != min_digits--)
		ft_printf_write("0", 1, flags);
	while (len-- != 0)
	{
		c = '0' + (ABS((power / ft_power(10, len)) % 10));
		ft_printf_write(&c, 1, flags);
	}
	return (flags->error) ? -1 : flags->chars_wr;
}

static int	do_a(long double nbr, t_flags *flags)
{
	int		power;
	int		left;
	char	*hex;

	hex = "0123456789abcdef";
	ft_printf_write("0x", 2, flags);
	power = get_power(&nbr);
	power += round(&nbr, flags);
	left = flags->precision;
	ft_printf_write(&hex[(int)nbr], 1, flags);
	if ((nbr != 0 && (nbr - (int)nbr != 0) && left != 0) || flags->alternative
			|| flags->precision > 0)
		ft_printf_write(".", 1, flags);
	while ((nbr != 0 && (nbr - (int)nbr != 0) && flags->precision == -1) ||
			(left-- != 0 && flags->precision != -1))
	{
		nbr = (nbr - (int)nbr) * 16;
		ft_printf_write(&hex[(int)nbr], 1, flags);
	}
	ft_printf_write("p", 1, flags);
	ft_putpower(power, flags, 1);
	return (flags->error) ? -1 : flags->chars_wr;
}

int			format_a(t_flags *flags, va_list ap)
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
		do_a(val, flags);
	flags->just_count = false;
	flags->positive = (val < 0) ? false : true;
	format_before(flags);
	if (is_nan(val) || is_inf(val))
		ft_printf_write(is_nan(val) ? "nan" : "inf", 3, flags);
	else
		flags->chars_wr = do_a(val, flags);
	format_after(flags);
	return (flags->chars_wr);
}
