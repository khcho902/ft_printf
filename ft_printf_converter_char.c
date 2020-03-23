/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_converter_char.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kycho <kycho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 02:05:43 by kycho             #+#    #+#             */
/*   Updated: 2020/03/23 19:10:47 by kycho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_printf_converter_char(t_printf_condition *c, t_printf_flag *f)
{
	char *res;
	size_t idx;
	
//	if (f->space || f->zero || f->precision_exist)
//		return (NULL);
	f->res_len = (f->width != 0) ? f->width : 1;
	res = (char *)malloc(sizeof(char) * f->res_len);
	if (res == NULL)
		return (NULL);
	ft_memset(res, ' ', f->res_len);
	idx = (f->minus != 0) ? 0 : f->res_len - 1;
	res[idx] = va_arg(c->ap, int);
	return (res);
}
