/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_options.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 18:19:44 by ofedorov          #+#    #+#             */
/*   Updated: 2017/02/03 18:19:54 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_ARGUMENTS_H
# define FT_LS_ARGUMENTS_H

typedef uint8_t t_options;

# define OPTION_LONG_FORMAT			1
# define OPTION_RECURSIVE			2
# define OPTION_REVERSE				4
# define OPTION_INCLUDE_DOT_FILES	8
# define OPTION_TIME_SORT			16
# define OPTION_SEVERAL_FILES		32

#endif
