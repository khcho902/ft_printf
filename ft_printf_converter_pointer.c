/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_converter_pointer.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kycho <kycho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 22:02:57 by kycho             #+#    #+#             */
/*   Updated: 2020/04/09 00:10:06 by kycho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*get_sub_pointer(t_printf_flag *f, void *p)
{
	char	*sub_pointer;
	size_t	len;
	char	*tmp;
	size_t	idx;

	sub_pointer = ft_ultoa_base((size_t)p, "0123456789abcdef");
	len = ft_strlen(sub_pointer);
	if (f->precision_exist && f->precision > len)
	{
		tmp = sub_pointer;
		if (!(sub_pointer = malloc(sizeof(char) * (f->precision + 1))))
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
	if (p == NULL && f->precision_exist && f->precision == 0)
		sub_pointer = ft_strdup("");
	else
		sub_pointer = get_sub_pointer(f, p);
	if (sub_pointer == NULL)
		return (NULL);
	pointer = ft_strjoin("0x", sub_pointer);
	free(sub_pointer);
	return (pointer);
}

int			ft_printf_converter_pointer(
					t_printf_condition *c, t_printf_flag *f, t_printf_res *r)
{
	char	*pointer;
	size_t	pointer_len;
	size_t	idx;

	if (!(pointer = get_pointer(c, f)))
		return (-1);
	pointer_len = ft_strlen(pointer);
	r->res_len = (f->width > pointer_len) ? f->width : pointer_len;
	if (!(r->res = (char *)malloc(sizeof(char) * r->res_len)))
		return (-1);
	idx = (f->minus != 0) ? 0 : r->res_len - pointer_len;
	ft_memset(r->res, ' ', r->res_len);
	ft_memcpy(&r->res[idx], pointer, pointer_len);
	free(pointer);
	return (1);
}
