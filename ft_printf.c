/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kycho <kycho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 16:54:50 by kycho             #+#    #+#             */
/*   Updated: 2020/04/10 21:29:50 by kycho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int					total_written;
	int					written;
	char				*specifiers;
	t_printf_condition	condition;

	if (format == NULL)
		return (ERROR);
	total_written = 0;
	specifiers = FT_PRINTF_SPECIFIERS;
	condition.format = format;
	va_start(condition.ap, format);
	condition.fd = FT_PRINTF_FD;
	while (*condition.format != '\0')
	{
		if (*condition.format == FT_PRINTF_TARGET)
			written = ft_printf_conversion_handler(&condition, specifiers);
		else
			written = ft_printf_putchar(&condition);
		if (written == ERROR)
			return (ERROR);
		total_written += written;
	}
	va_end(condition.ap);
	return (total_written);
}
