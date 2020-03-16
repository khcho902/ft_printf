/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_converter_char.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kycho <kycho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 02:05:43 by kycho             #+#    #+#             */
/*   Updated: 2020/03/17 02:29:05 by kycho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_printf_converter_char(t_printf_condition *c, t_printf_flag *f)
{
	char *res_str;
	size_t res_str_len;
	size_t idx;
	
	if (f->space || f->zero || f->precision_exist)
		return (NULL);
	res_str_len = (f->width != 0) ? f->width : 1;
	res_str = (char *)malloc(sizeof(char) * (res_str_len + 1));
	if (res_str == NULL)
		return (NULL);
	ft_memset(res_str, ' ', res_str_len);
	res_str[res_str_len] = '\0';
	idx = (f->minus != 0) ? 0 : res_str_len - 1;
	res_str[idx] = va_arg(c->ap, int);
	return (res_str);
}
