/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_specifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kycho <kycho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 20:30:39 by kycho             #+#    #+#             */
/*   Updated: 2020/03/15 20:31:17 by kycho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char    ft_get_specifier(const char *format, const char *specifiers)
{
	size_t idx;

	idx = 1;
	while (format[idx])
	{
		if (ft_isinset(format[idx], specifiers))
			break;
		idx++;
	}
	return (format[idx]);
}
