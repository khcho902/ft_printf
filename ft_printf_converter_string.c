/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_converter_string.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kycho <kycho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 16:15:39 by kycho             #+#    #+#             */
/*   Updated: 2020/03/17 03:21:56 by kycho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>


size_t	get_write_str_len(t_printf_flag *f, size_t str_len)
{
	size_t len;

	if (f->precision_exist)
		len = (str_len < f->precision) ? str_len : f->precision;
	else
		len = str_len;
	return (len);
}

char	*ft_printf_converter_string(t_printf_condition *c, t_printf_flag *f)
{
	char *arg_str;
	char *res_str;
	size_t res_str_len;
	size_t write_str_len;
	size_t idx;

	if (f->space || f->zero)
		return (NULL);
	arg_str = va_arg(c->ap, char *);
	write_str_len = get_write_str_len(f, ft_strlen(arg_str));
	res_str_len = (write_str_len > f->width) ? write_str_len : f->width;
	res_str = (char *)malloc(sizeof(char) *(res_str_len + 1));
	if (res_str == NULL)
		return (NULL);
	ft_memset(res_str, ' ',res_str_len);
	res_str[res_str_len] = '\0';
	idx = (f->minus != 0) ? 0 : res_str_len - write_str_len;
	ft_memcpy(&res_str[idx], arg_str, write_str_len);
	return (res_str);
}
