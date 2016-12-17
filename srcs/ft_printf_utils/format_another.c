/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_another.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 14:01:18 by ofedorov          #+#    #+#             */
/*   Updated: 2016/12/04 14:01:28 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

static int	do_another(t_flags *flags)
{
	if (flags->format)
		ft_printf_write(&flags->format, 1, flags);
	return (flags->error) ? -1 : flags->chars_wr;
}

int			format_another(t_flags *flags, va_list ap)
{
	(void)ap;
	flags->chars_val = (flags->format) ? 1 : 0;
	format_before(flags);
	do_another(flags);
	format_after(flags);
	return (flags->chars_wr);
}
