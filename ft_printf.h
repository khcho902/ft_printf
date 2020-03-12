/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kycho <kycho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 16:55:00 by kycho             #+#    #+#             */
/*   Updated: 2020/03/12 23:28:10 by kycho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include "./libft/libft.h"

#define FT_PRINTF_TARGET '%'
#define FT_PRINTF_SPECIFIERS "cspdiuxX%"
#define	FT_PRINTF_FLAGS "-0.*"
#define FT_PRINTF_FD STDOUT

typedef struct	s_printf_condition
{
	const char	*format;
	size_t		idx;
	va_list		ap;
	int		fd;
	int		written_cnt;
}		t_printf_condition;


int	ft_printf(const char * format, ...);
void	ft_conversion_handler(t_printf_condition *condition);
void	ft_printf_putchar(t_printf_condition *condition);


#endif
