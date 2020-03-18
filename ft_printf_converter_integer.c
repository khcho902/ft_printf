/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_converter_integer.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kycho <kycho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 22:52:41 by kycho             #+#    #+#             */
/*   Updated: 2020/03/19 01:16:31 by kycho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

char	*ft_printf_converter_integer(t_printf_condition *c, t_printf_flag *f)
{
	char *res_str;
	size_t res_str_len;
	int minus;
	long num;
	char *pnum_str;
	size_t pnum_str_len;
	size_t write_pnum_str_len;
	size_t idx;

	if (f->zero && f->minus)
		return (NULL);
	if (f->precision_exist)
		f->zero = 0;

	minus = 0;
	num = va_arg(c->ap,int);
	if (num < 0)
	{
		num *= -1;
		minus = 1;
	}
	
	pnum_str = ft_uitoa(num);
	if (pnum_str == NULL)
		return (NULL);
	pnum_str_len = ft_strlen(pnum_str);

	/////
	write_pnum_str_len = pnum_str_len;
	if (f->precision > pnum_str_len)
		write_pnum_str_len = f->precision;

	/////
	res_str_len = write_pnum_str_len;
	if (minus || f->space)
		res_str_len++;
	if (f->width > res_str_len)
		res_str_len = f->width;

	/////
	res_str = (char *)malloc(sizeof(char) * (res_str_len + 1));
	if (res_str == NULL)
		return (NULL);
	res_str[res_str_len] = '\0';

	
	/////
	if (f->zero)
	{
		ft_memset(res_str, '0', res_str_len);
		idx = res_str_len - pnum_str_len;
		ft_memcpy(&res_str[idx], pnum_str, pnum_str_len);
		if (f->space)
			res_str[0] = ' ';
		if (minus)
			res_str[0] = '-';
	}
	else
	{
		ft_memset(res_str, ' ', res_str_len);
		idx = res_str_len - write_pnum_str_len;
		if (f->minus)
			idx = (minus) ? 1 : 0;
		if (minus)
			res_str[idx - 1] = '-';
		ft_memset(&res_str[idx], '0', write_pnum_str_len);
		idx = idx + write_pnum_str_len - pnum_str_len;
		ft_memcpy(&res_str[idx], pnum_str, pnum_str_len);
	}

	/*
	printf("pnum_str : %s\n", pnum_str);
	printf("minus : %d\n", minus);

	char *str = malloc(4);
	str[0] = 'a';
	str[1] = 'a';
	str[2] = 'a';
	str[3] = '\0';

	return (str);
	*/
	return (res_str);
}
