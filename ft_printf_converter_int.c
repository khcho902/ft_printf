/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_converter_int.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kycho <kycho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 22:52:41 by kycho             #+#    #+#             */
/*   Updated: 2020/03/23 19:00:43 by kycho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	init(va_list ap, t_printf_flag *f, long *n, int *minus)
{
	if (f->minus || f->precision_exist)
		f->zero = 0;
	*minus = 0;
	*n = va_arg(ap,int);
	if (*n < 0)
	{
		*n *= -1;
		*minus = 1;
	}
}

static size_t	get_write_pnum_len(t_printf_flag *f, size_t pnum_len)
{
	size_t write_pnum_len;
	write_pnum_len = pnum_len;
	if (f->precision > pnum_len)
		write_pnum_len = f->precision;
	return (write_pnum_len);
}

static size_t	get_res_len(t_printf_flag *f, size_t write_pnum_len, int minus)
{
	size_t res_len;
	res_len = write_pnum_len;
	if (minus || f->space)
		res_len++;
	if (f->width > res_len)
		res_len = f->width;
	return (res_len);
}


static void	set_res(t_printf_flag *f, t_num_str *num, char *res, size_t len)
{
	size_t idx;

	if (f->zero)
	{
		ft_memset(res, '0', len);
		idx = len - num->pnum_len;
		ft_memcpy(&res[idx], num->pnum, num->pnum_len);
		if (f->space)
			res[0] = ' ';
		if (num->minus)
			res[0] = '-';
	}
	else
	{
		ft_memset(res, ' ', len);
		idx = len - num->write_pnum_len;
		if (f->minus)
			idx = (num->minus) ? 1 : 0;
		if (num->minus)
			res[idx - 1] = '-';
		ft_memset(&res[idx], '0', num->write_pnum_len);
		idx = idx + num->write_pnum_len - num->pnum_len;
		ft_memcpy(&res[idx], num->pnum, num->pnum_len);
	}
}

char	*ft_printf_converter_int(t_printf_condition *c, t_printf_flag *f)
{
	char *res;
	long n;
	t_num_str num;

	init(c->ap, f, &n, &num.minus);
	if (f->precision_exist && f->precision == 0 && n == 0)
		num.pnum = ft_strdup("");
	else
		num.pnum = ft_uitoa(n);
	if (num.pnum == NULL)
		return (NULL);
	num.pnum_len = ft_strlen(num.pnum);
	num.write_pnum_len = get_write_pnum_len(f, num.pnum_len);
	f->res_len = get_res_len(f, num.write_pnum_len, num.minus);
	res = (char *)malloc(sizeof(char) * f->res_len);
	if (res == NULL)
		return (NULL);
	set_res(f, &num, res, f->res_len);
	free(num.pnum);
	return (res);
}
