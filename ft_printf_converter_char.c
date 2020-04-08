/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_converter_char.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kycho <kycho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 02:05:43 by kycho             #+#    #+#             */
/*   Updated: 2020/04/09 00:49:08 by kycho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_converter_char(
				t_printf_condition *c, t_printf_flag *f, t_printf_res *r)
{
	size_t	idx;

	r->res_len = (f->width != 0) ? f->width : 1;
	r->res = (char *)malloc(sizeof(char) * r->res_len);
	if (r->res == NULL)
		return (ERROR);
	ft_memset(r->res, ' ', r->res_len);
	idx = (f->minus != 0) ? 0 : r->res_len - 1;
	r->res[idx] = va_arg(c->ap, int);
	return (SUCCESS);
}
