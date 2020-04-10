/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_converter_percent.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kycho <kycho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 22:32:41 by kycho             #+#    #+#             */
/*   Updated: 2020/04/10 13:53:04 by kycho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		adjust_flag(t_printf_flag *f)
{
	if (f->minus)
		f->zero = 0;
}

static int		set_content(va_list ap, t_printf_flag *f, t_printf_content *pc)
{
	if (f == NULL && va_arg(ap, int))
		return (ERROR);
	pc->content = ft_strdup("%");
	if (pc->content == NULL)
		return (ERROR);
	pc->content_len = ft_strlen(pc->content);
	return (SUCCESS);
}

static int		set_res(t_printf_flag *f, t_printf_res *r, t_printf_content *pc)
{
	size_t idx;

	r->res_len = ft_sizet_max(f->width, pc->content_len);
	if (!(r->res = (char *)malloc(sizeof(char) * r->res_len)))
		return (ERROR);
	if (f->zero)
		ft_memset(r->res, '0', r->res_len);
	else
		ft_memset(r->res, ' ', r->res_len);
	idx = (f->minus) ? 0 : r->res_len - pc->content_len;
	ft_memcpy(&r->res[idx], pc->content, pc->content_len);
	return (SUCCESS);
}

int				ft_printf_converter_percent(
					t_printf_condition *c, t_printf_flag *f, t_printf_res *r)
{
	t_printf_content	pc;

	adjust_flag(f);
	if (set_content(c->ap, f, &pc) == ERROR)
		return (ERROR);
	if (set_res(f, r, &pc) == ERROR)
		return (ERROR);
	free(pc.content);
	return (SUCCESS);
}
