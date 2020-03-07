/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kycho <kycho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 20:27:06 by kycho             #+#    #+#             */
/*   Updated: 2020/03/07 22:41:47 by kycho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_vfprintf(int fd, const char *format, va_list arg)
{
	size_t idx;

	idx = 0;
	while (format[idx])
	{
		if (format[idx] == FT_PRINTF_FORMAT_CHAR)
		{
			idx++;
			idx += ft_conversion_handler(fd, &format[idx], arg);
		}
		else
		{
			ft_putchar_fd(format[idx], fd);
			idx++;
		}
	}
	// return value 수정해야함
	return (0);
}
