/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_converter_hex.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kycho <kycho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 22:09:54 by kycho             #+#    #+#             */
/*   Updated: 2020/04/07 13:14:27 by kycho            ###   ########.fr       */
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

static void		set_res(t_printf_flag *f, t_num_str *num, char *res, size_t len)
{
	size_t idx;

	if (f->zero)
	{
		ft_memset(res, '0', len);
		idx = len - num->pnum_len;
		ft_memcpy(&res[idx], num->pnum, num->pnum_len);
	}
	else
	{
		ft_memset(res, ' ', len);
		idx = len - num->write_pnum_len;
		if (f->minus)
			idx = 0;
		ft_memset(&res[idx], '0', num->write_pnum_len);
		idx = idx + num->write_pnum_len - num->pnum_len;
		ft_memcpy(&res[idx], num->pnum, num->pnum_len);
	}
}

char			*ft_printf_converter_hex(
									t_printf_condition *c, t_printf_flag *f)
{
	char			*res;
	unsigned int	n;
	t_num_str		num;
	char			*base;

	init(c->ap, f, &n, &base);
	if (f->precision_exist && f->precision == 0 && n == 0)
		num.pnum = ft_strdup("");
	else
		num.pnum = ft_uitoa_base(n, base);
	if (num.pnum == NULL)
		return (NULL);
	num.pnum_len = ft_strlen(num.pnum);
	num.write_pnum_len = get_write_pnum_len(f, num.pnum_len);
	f->res_len = get_res_len(f, num.write_pnum_len);
	res = (char *)malloc(sizeof(char) * f->res_len);
	if (res == NULL)
		return (NULL);
	set_res(f, &num, res, f->res_len);
	free(num.pnum);
	return (res);
}
