/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_converter_char.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kycho <kycho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 02:05:43 by kycho             #+#    #+#             */
/*   Updated: 2020/03/16 04:48:20 by kycho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_printf_converter_char(t_printf_condition *c, t_printf_flag *f)
{
	char *str;
	size_t need_len;
	size_t idx;
/*
	str = (char *)malloc(sizeof(char) * 10);
	str[0] = 'h';
	str[1] = 'e';
	str[2] = 'l';
	str[3] = 'l';
	str[4] = 'o';
	str[5] = 'w';
	str[6] = '\0';
*/
	if (f->space || f->zero || f->precision_exist)
		return (NULL);
	need_len = (f->width != 0) ? f->width : 1;
	str = (char *)malloc(sizeof(char) * (need_len + 1));
	if (str == NULL)
		return (NULL);
	ft_memset(str, ' ', need_len);
	str[need_len] = '\0';
	idx = (f->minus != 0) ? 0 : need_len - 1;
	str[idx] = va_arg(c->ap, int);
	return (str);
}
