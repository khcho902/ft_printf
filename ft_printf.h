/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kycho <kycho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 23:36:16 by kycho             #+#    #+#             */
/*   Updated: 2020/03/07 22:42:30 by kycho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include "libft/libft.h"

#define FT_PRINTF_FD STDOUT
#define FT_PRINTF_FORMAT_CHAR '%'
#define FT_PRINTF_CONVERSION_CHARS "cspdiuxX%"

int	ft_printf(const char *format, ...);
int	ft_vfprintf(int fd, const char *format, va_list ap);
size_t	ft_conversion_handler(int fd, const char *sub_format, va_list ap);


// 구현 아직 안함
int	ft_is_conversion_char(char ch);


#endif
