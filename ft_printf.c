/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kycho <kycho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 23:34:33 by kycho             #+#    #+#             */
/*   Updated: 2020/03/07 20:29:52 by kycho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char * format, ...)
{
	va_list arg;
	int done;

	va_start(arg, format);
	done = ft_vfprintf(STDOUT, format, arg);
	va_end(arg);

	return (done);
}
