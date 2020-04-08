/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_converter_string.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kycho <kycho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 16:15:39 by kycho             #+#    #+#             */
/*   Updated: 2020/04/09 00:49:43 by kycho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		init(va_list ap, t_printf_flag *f, char **arg)
{
	if (f->minus)
		f->zero = 0;
	*arg = va_arg(ap, char *);
	if (*arg == NULL)
		*arg = "(null)";
}

static size_t	get_write_len(t_printf_flag *f, size_t str_len)
{
	size_t len;

	if (f->precision_exist)
		len = (str_len < f->precision) ? str_len : f->precision;
	else
		len = str_len;
	return (len);
}

static size_t	get_res_len(t_printf_flag *f, size_t write_len)
{
	size_t res_len;

	res_len = (write_len > f->width) ? write_len : f->width;
	return (res_len);
}

static void		set_res(
		t_printf_flag *f, t_printf_res *r, const char *arg, size_t write_len)
{
	size_t idx;

	if (f->zero)
		ft_memset(r->res, '0', r->res_len);
	else
		ft_memset(r->res, ' ', r->res_len);
	idx = (f->minus != 0) ? 0 : r->res_len - write_len;
	ft_memcpy(&r->res[idx], arg, write_len);
}

int				ft_printf_converter_string(
					t_printf_condition *c, t_printf_flag *f, t_printf_res *r)
{
	char	*arg;
	size_t	write_len;

	init(c->ap, f, &arg);
	write_len = get_write_len(f, ft_strlen(arg));
	r->res_len = get_res_len(f, write_len);
	if (!(r->res = (char *)malloc(sizeof(char) * r->res_len)))
		return (ERROR);
	set_res(f, r, arg, write_len);
	return (SUCCESS);
}
