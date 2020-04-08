/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_converter_int.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kycho <kycho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 22:52:41 by kycho             #+#    #+#             */
/*   Updated: 2020/04/09 03:46:17 by kycho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		init(va_list ap, t_printf_flag *f, long *n, t_printf_content *pc)
{
	if (f->minus || f->precision_exist)
		f->zero = 0;
	*n = va_arg(ap, int);
	if (*n < 0)
	{
		*n *= -1;
		pc->prefix = ft_strdup("-");
	} 
	else if (f->space)
		pc->prefix = ft_strdup(" ");
	else
		pc->prefix = ft_strdup("");
	pc->prefix_len = ft_strlen(pc->prefix);
}

static size_t	get_must_content_len(t_printf_flag *f, size_t content_len)
{
	size_t must_content_len;

	must_content_len = content_len;
	if (f->precision > content_len)
		must_content_len = f->precision;
	return (must_content_len);
}

static size_t	get_res_len(t_printf_flag *f, t_printf_content *pc)
{
	size_t res_len;

	res_len = pc->must_content_len;
	res_len += pc->prefix_len;
	if (f->width > res_len)
		res_len = f->width;
	return (res_len);
}

static void		set_res(t_printf_flag *f, t_printf_res *r, t_printf_content *pc)
{
	size_t idx;

	if (f->zero)
	{
		ft_memset(r->res, '0', r->res_len);
		idx = r->res_len - pc->content_len;
		ft_memcpy(&r->res[idx], pc->content, pc->content_len);
		ft_memcpy(&r->res[0], pc->prefix, pc->prefix_len);
	}
	else
	{
		ft_memset(r->res, ' ', r->res_len);
		idx = r->res_len - pc->must_content_len;
		if (f->minus)
			idx = pc->prefix_len;
		ft_memcpy(&r->res[idx - pc->prefix_len], pc->prefix, pc->prefix_len);
		ft_memset(&r->res[idx], '0', pc->must_content_len);
		idx = idx + pc->must_content_len - pc->content_len;
		ft_memcpy(&r->res[idx], pc->content, pc->content_len);
	}
}

int				ft_printf_converter_int(
					t_printf_condition *c, t_printf_flag *f, t_printf_res *r)
{
	long				n;
	t_printf_content	pc;

	init(c->ap, f, &n, &pc);
	if (f->precision_exist && f->precision == 0 && n == 0)
		pc.content = ft_strdup("");
	else
		pc.content = ft_uitoa(n);
	if (pc.content == NULL)
		return (ERROR);
	pc.content_len = ft_strlen(pc.content);


	pc.must_content_len = get_must_content_len(f, pc.content_len);
	r->res_len = get_res_len(f, &pc);
	r->res = (char *)malloc(sizeof(char) * r->res_len);
	if (r->res == NULL)
		return (ERROR);
	set_res(f, r, &pc);
	free(pc.prefix);
	free(pc.content);
	return (SUCCESS);
}
