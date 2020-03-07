/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kycho <kycho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 20:27:06 by kycho             #+#    #+#             */
/*   Updated: 2020/03/07 21:28:19 by kycho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

int	ft_vfprintf(int fd, const char *format, va_list arg)
{
	size_t i;
	char ch;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i+ 1] == 'c')
			{
				ch = va_arg(arg, int);
				write(STDOUT, &ch, 1);
				i++;
			}
		}
		else
		{
			write(STDOUT, &format[i], 1);
		}
		i++;
	}
	return (0);
}
