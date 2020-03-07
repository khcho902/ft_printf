/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kycho <kycho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 23:36:16 by kycho             #+#    #+#             */
/*   Updated: 2020/03/07 20:29:40 by kycho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include "libft/libft.h"

# define STDIN 0
# define STDOUT 1
# define STDERR 2

int	ft_printf(const char *format, ...);
int	ft_vfprintf(int fd, const char *format, va_list arg);


#endif
