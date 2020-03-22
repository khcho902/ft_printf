/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_converter_pointer.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kycho <kycho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 22:02:57 by kycho             #+#    #+#             */
/*   Updated: 2020/03/22 21:52:50 by kycho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*get_sub_pointer(t_printf_flag *f, void *p)
{
	char *sub_pointer;
	size_t len;
	char *tmp;
	size_t idx;

	sub_pointer = ft_ultoa_base((size_t)p, "0123456789abcdef");
	len = ft_strlen(sub_pointer);
	if (f->precision_exist && f->precision > len)
	{
		tmp = sub_pointer;
		if(!(sub_pointer = malloc(sizeof(char) * (f->precision + 1))))
			return (NULL);
		sub_pointer[f->precision] = '\0';
		ft_memset(sub_pointer, '0', f->precision);
		idx = f->precision - len;
		ft_memcpy(&sub_pointer[idx], tmp, len);
		free(tmp);
	}
	return (sub_pointer);
}

static char	*get_pointer(t_printf_condition *c, t_printf_flag *f)
{
	void *p;
	char *sub_pointer;
	char *pointer;
	
	p = va_arg(c->ap, void *);
	if (p == NULL)
	{
		pointer = ft_strdup("(nil)");
	}
	else
	{
		if (!(sub_pointer = get_sub_pointer(f, p)))
			return (NULL);
		pointer = ft_strjoin("0x", sub_pointer);
		free(sub_pointer);
	}
	return (pointer);
}

char	*ft_printf_converter_pointer(t_printf_condition *c, t_printf_flag *f)
{
	char *res;
	size_t res_len;
	char *pointer;
	size_t pointer_len;
	size_t idx;

	if (!(pointer = get_pointer(c, f)))
		return (NULL);
	pointer_len = ft_strlen(pointer);
	res_len = (f->width > pointer_len) ? f->width : pointer_len;
	if(!(res = (char *)malloc(sizeof(char) *(res_len + 1))))
		return (NULL);
	res[res_len] = '\0';
	idx = (f->minus != 0) ? 0 : res_len - pointer_len;
	ft_memset(res, ' ', res_len);
	ft_memcpy(&res[idx], pointer, pointer_len);
	free(pointer);
	return (res);
}
