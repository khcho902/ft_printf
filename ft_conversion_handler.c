/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_handler.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kycho <kycho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 22:05:43 by kycho             #+#    #+#             */
/*   Updated: 2020/03/07 22:33:00 by kycho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_conversion_handler(int fd, const char *sub_format, va_list ap)
{
	size_t len;

	len = 0;
	while (!ft_is_conversion_char(sub_format[len]))
		len++;
	
	write(FT_PRINTF_FD, "%", 1);

	return (len);
}
