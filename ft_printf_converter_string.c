/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_converter_string.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kycho <kycho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 16:15:39 by kycho             #+#    #+#             */
/*   Updated: 2020/04/07 13:08:32 by kycho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	get_write_len(t_printf_flag *f, size_t str_len)
{
	size_t len;

	if (f->precision_exist)
		len = (str_len < f->precision) ? str_len : f->precision;
	else
		len = str_len;
	return (len);
}

char			*ft_printf_converter_string(
									t_printf_condition *c, t_printf_flag *f)
{
	char	*arg;
	char	*res;
	size_t	write_len;
	size_t	idx;

	if (!(arg = va_arg(c->ap, char *)))
	{
		arg = "(null)";
		if (f->precision_exist && f->precision < ft_strlen(arg))
			f->precision = 0;
	}
	write_len = get_write_len(f, ft_strlen(arg));
	f->res_len = (write_len > f->width) ? write_len : f->width;
	if (!(res = (char *)malloc(sizeof(char) * f->res_len)))
		return (NULL);
	ft_memset(res, ' ', f->res_len);
	idx = (f->minus != 0) ? 0 : f->res_len - write_len;
	ft_memcpy(&res[idx], arg, write_len);
	return (res);
}
