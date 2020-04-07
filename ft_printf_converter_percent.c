/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_converter_percent.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kycho <kycho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 22:32:41 by kycho             #+#    #+#             */
/*   Updated: 2020/04/07 23:51:15 by kycho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	init(t_printf_flag *f)
{
	if (f->minus)
		f->zero = 0;
}

static size_t get_res_len(t_printf_flag *f)
{
	size_t res_len;

	res_len = (f->width > 1) ? f->width : 1;
	return (res_len);
}

static void set_res(t_printf_flag *f, char *res)
{
	size_t idx;

	if (f->zero)
		ft_memset(res, '0', f->res_len);
	else
		ft_memset(res, ' ', f->res_len);
	idx = (f->minus) ? 0 : f->res_len - 1;
	res[idx] = '%';
}

char	*ft_printf_converter_percent(t_printf_condition *c, t_printf_flag *f)
{
	char *res;

	if (c == NULL || f == NULL)
		return (NULL);
	init(f);
	f->res_len = get_res_len(f);
	res = (char *)malloc(sizeof(char) * f->res_len);
	if (res == NULL)
		return (NULL);
	set_res(f, res);
	return (res);
}
