/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_converter_hex.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kycho <kycho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 22:09:54 by kycho             #+#    #+#             */
/*   Updated: 2020/04/08 23:43:27 by kycho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		init(va_list ap, t_printf_flag *f, unsigned int *n, char **b)
{
	if (f->minus || f->precision_exist)
		f->zero = 0;
	*n = va_arg(ap, unsigned int);
	if (f->specifier == 'x')
		*b = "0123456789abcdef";
	else
		*b = "0123456789ABCDEF";
}

static size_t	get_write_pnum_len(t_printf_flag *f, size_t pnum_len)
{
	size_t write_pnum_len;

	write_pnum_len = pnum_len;
	if (f->precision > pnum_len)
		write_pnum_len = f->precision;
	return (write_pnum_len);
}

static size_t	get_res_len(t_printf_flag *f, size_t write_pnum_len)
{
	size_t res_len;

	res_len = write_pnum_len;
	if (f->width > res_len)
		res_len = f->width;
	return (res_len);
}

static void		set_res(t_printf_flag *f, t_printf_res *r, t_num_str *num)
{
	size_t idx;

	if (f->zero)
	{
		ft_memset(r->res, '0', r->res_len);
		idx = r->res_len - num->pnum_len;
		ft_memcpy(&r->res[idx], num->pnum, num->pnum_len);
	}
	else
	{
		ft_memset(r->res, ' ', r->res_len);
		idx = r->res_len - num->write_pnum_len;
		if (f->minus)
			idx = 0;
		ft_memset(&r->res[idx], '0', num->write_pnum_len);
		idx = idx + num->write_pnum_len - num->pnum_len;
		ft_memcpy(&r->res[idx], num->pnum, num->pnum_len);
	}
}

int				ft_printf_converter_hex(
					t_printf_condition *c, t_printf_flag *f, t_printf_res *r)
{
	unsigned int	n;
	t_num_str		num;
	char			*base;

	init(c->ap, f, &n, &base);
	if (f->precision_exist && f->precision == 0 && n == 0)
		num.pnum = ft_strdup("");
	else
		num.pnum = ft_uitoa_base(n, base);
	if (num.pnum == NULL)
		return (-1);
	num.pnum_len = ft_strlen(num.pnum);
	num.write_pnum_len = get_write_pnum_len(f, num.pnum_len);
	r->res_len = get_res_len(f, num.write_pnum_len);
	r->res = (char *)malloc(sizeof(char) * r->res_len);
	if (r->res == NULL)
		return (-1);
	set_res(f, r, &num);
	free(num.pnum);
	return (1);
}
