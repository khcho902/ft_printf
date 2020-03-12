/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kycho <kycho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 16:54:50 by kycho             #+#    #+#             */
/*   Updated: 2020/03/12 23:40:44 by kycho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char * format, ...)
{
	t_printf_condition condition;
	
	condition.format = format;
	condition.idx = 0;
	va_start(condition.ap, format);
	condition.fd = FT_PRINTF_FD;
	condition.written_cnt = 0;

	while (format[condition.idx] != '\0')
	{
		if (format[condition.idx] == FT_PRINTF_TARGET)
		{
			ft_conversion_handler(&condition);
		}
		else 
		{
			ft_printf_putchar(&condition);
		}
	}
	va_end(condition.ap);
	return (condition.written_cnt);
}
