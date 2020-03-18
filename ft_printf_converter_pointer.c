/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_converter_pointer.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kycho <kycho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 22:02:57 by kycho             #+#    #+#             */
/*   Updated: 2020/03/18 20:37:23 by kycho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_printf_converter_pointer(t_printf_condition *c, t_printf_flag *f)
{
	char *res_str;
	size_t res_str_len;
	void *pointer;
	char *pointer_str;
	size_t pointer_str_len;
	size_t idx;

	if (f->zero || f->space || f->precision_exist)
		return (NULL);
	pointer = va_arg(c->ap, void *);
	if(!(pointer_str = ft_ultoa_base((size_t)pointer, "0123456789abcdef")))
		return (NULL);
	pointer_str_len = ft_strlen(pointer_str);
	res_str_len = pointer_str_len + 2;
	res_str_len = (f->width > res_str_len) ? f->width : res_str_len;
	if(!(res_str = (char *)malloc(sizeof(char) *(res_str_len + 1))))
		return (NULL);
	res_str[res_str_len] = '\0';
	idx = (f->minus != 0) ? 2 : res_str_len - pointer_str_len;
	ft_memset(res_str, ' ', res_str_len);
	ft_memcpy(&res_str[idx], pointer_str, pointer_str_len);
	ft_memcpy(&res_str[idx-2], "0x", 2);
	free(pointer_str);
	return (res_str);
}
