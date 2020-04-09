/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_converter_int.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kycho <kycho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 22:52:41 by kycho             #+#    #+#             */
/*   Updated: 2020/04/09 18:25:28 by kycho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		set_content(va_list ap, t_printf_flag *f, t_printf_content *pc)
{
	long n;

	n = va_arg(ap, int);
	if (n < 0)
		pc->prefix = ft_strdup("-");
	else if (f->space)
		pc->prefix = ft_strdup(" ");
	else
		pc->prefix = ft_strdup("");
	if (pc->prefix == NULL)
		return (ERROR);
	pc->prefix_len = ft_strlen(pc->prefix);
	if (f->precision_exist && f->precision == 0 && n == 0)
		pc->content = ft_strdup("");
	else
		pc->content = ft_uitoa((n >= 0) ? n : n * -1);
	if (pc->content == NULL)
		return (ERROR);
	pc->content_len = ft_strlen(pc->content);
	pc->must_content_len = pc->content_len;
	if (f->precision > pc->content_len)
		pc->must_content_len = f->precision;
	return (SUCCESS);
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

static int		set_res(t_printf_flag *f, t_printf_res *r, t_printf_content *pc)
{
	size_t idx;

	r->res_len = get_res_len(f, pc);
	if (!(r->res = (char *)malloc(sizeof(char) * r->res_len)))
		return (ERROR);
	if (f->zero)
	{
		ft_memset(r->res, '0', r->res_len);
		ft_memcpy(&r->res[0], pc->prefix, pc->prefix_len);
		idx = r->res_len - pc->content_len;
	}
	else
	{
		ft_memset(r->res, ' ', r->res_len);
		idx = f->minus ? pc->prefix_len : r->res_len - pc->must_content_len;
		ft_memcpy(&r->res[idx - pc->prefix_len], pc->prefix, pc->prefix_len);
		ft_memset(&r->res[idx], '0', pc->must_content_len);
		idx = idx + pc->must_content_len - pc->content_len;
	}
	ft_memcpy(&r->res[idx], pc->content, pc->content_len);
	return (SUCCESS);
}

int				ft_printf_converter_int(
					t_printf_condition *c, t_printf_flag *f, t_printf_res *r)
{
	t_printf_content	pc;

	if (f->minus || f->precision_exist)
		f->zero = 0;
	if (set_content(c->ap, f, &pc) == ERROR)
		return (ERROR);
	if (set_res(f, r, &pc) == ERROR)
		return (ERROR);
	free(pc.prefix);
	free(pc.content);
	return (SUCCESS);
}
