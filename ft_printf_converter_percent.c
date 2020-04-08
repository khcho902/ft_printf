/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_converter_percent.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kycho <kycho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 22:32:41 by kycho             #+#    #+#             */
/*   Updated: 2020/04/09 00:24:58 by kycho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		init(t_printf_flag *f)
{
	if (f->minus)
		f->zero = 0;
}

static size_t	get_res_len(t_printf_flag *f)
{
	size_t res_len;

	res_len = (f->width > 1) ? f->width : 1;
	return (res_len);
}

static void		set_res(t_printf_flag *f, t_printf_res *r)
{
	size_t idx;

	if (f->zero)
		ft_memset(r->res, '0', r->res_len);
	else
		ft_memset(r->res, ' ', r->res_len);
	idx = (f->minus) ? 0 : r->res_len - 1;
	r->res[idx] = '%';
}

int				ft_printf_converter_percent(
					t_printf_condition *c, t_printf_flag *f, t_printf_res *r)
{
	if (c == NULL)
		return (-1);
	init(f);
	r->res_len = get_res_len(f);
	r->res = (char *)malloc(sizeof(char) * r->res_len);
	if (r->res == NULL)
		return (-1);
	set_res(f, r);
	return (1);
}
