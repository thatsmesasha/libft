/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 15:18:00 by ofedorov          #+#    #+#             */
/*   Updated: 2016/12/17 13:45:19 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <libft.h>
# include <unistd.h>
# include <stdlib.h>
# include <locale.h>
# include <wchar.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stddef.h>
# include <float.h>

typedef char			t_case;
# define CAPITAL		'A'
# define SMALL			'a'

typedef unsigned		t_length_mod;
# define LEN_H			0
# define LEN_HH			1
# define LEN_NONE		2
# define LEN_L			3
# define LEN_LL			4
# define LEN_J			5
# define LEN_Z			6
# define LEN_T			7
# define LEN_L_CAP		8

typedef struct			s_flags
{
	int					fd;
	bool				capital;
	bool				left_justified;
	bool				sign;
	bool				positive;
	bool				space;
	bool				alternative;
	bool				zero;
	int					field_width;
	int					precision;
	bool				just_count;
	t_length_mod		length_mod;
	char				format;
	int					chars_wr;
	int					chars_val;
	char				*error;
}						t_flags;

# define ABS(x)			(x) < 0 ? -(x) : (x)
# define MAX(x, y)		(x) > (y) ? (x) : (y)
# define MIN(x, y)		(x) < (y) ? (x) : (y)

int						(*g_formats[128])(t_flags *flags, va_list ap);

void					ft_printf_write(const char *to_write, int size,
										t_flags *flags);
t_flags					*new_flags(int fd, char format, bool just_count);
t_flags					*read_format(int fd, const char **str, va_list ap);
void					format_before(t_flags *flags);
void					format_after(t_flags *flags);
int						switch_format(t_flags *flags, va_list ap, int ch_wr);
long double				get_value_feag(t_flags *flags, va_list ap);
unsigned long long int	get_value_oxu(t_flags *flags, va_list ap);
int						supported_format(char c);

void					check_length_mod(t_flags *flags, const char **format);
void					check_field_width_dig(t_flags *flags,
												const char **format);
void					check_field_width_star(t_flags *flags,
											const char **format, va_list ap);
void					check_l_mod(t_flags *flags);
void					check_specific_f(t_flags *flags);
void					determine_format(t_flags *flags, const char **f);
void					check_precision(t_flags *flags, const char **format,
										va_list ap);
void					check_flags(t_flags *flags, const char **format);

void					assign_false(int number, ...);
int						is_format(char c);
int						is_flag(char c);
int						is_len_mod(char c);

int						ft_printf(const char *format, ...);
int						ft_dprintf(int fd, const char *format, ...);
int						ft_vprintf(const char *format, va_list ap);
int						ft_vdprintf(int fd, const char *format, va_list ap);

int						is_nan(long double nbr);
int						is_inf(long double nbr);

int						format_a(t_flags *flags, va_list ap);
int						format_c(t_flags *flags, va_list ap);
int						format_d(t_flags *flags, va_list ap);
int						format_i(t_flags *flags, va_list ap);
int						format_e(t_flags *flags, va_list ap);
int						format_f(t_flags *flags, va_list ap);
int						format_s(t_flags *flags, va_list ap);
int						format_o(t_flags *flags, va_list ap);
int						format_u(t_flags *flags, va_list ap);
int						format_x(t_flags *flags, va_list ap);
int						format_p(t_flags *flags, va_list ap);
int						format_another(t_flags *flags, va_list ap);

int						ft_putpower(int power, t_flags *flags, int min_digits);

#endif
