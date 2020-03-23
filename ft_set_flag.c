/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kycho <kycho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 20:40:46 by kycho             #+#    #+#             */
/*   Updated: 2020/03/23 19:36:24 by kycho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    init_flag(t_printf_flag *flag, char specifier)
{
	flag->specifier = specifier;
	flag->res_len = 0;
	flag->space = 0;
	flag->zero = 0;
	flag->minus = 0;
	flag->width = 0;
	flag->precision_exist = 0;
	flag->precision = 0;
}

int     ft_set_flag(t_printf_flag *f, t_printf_condition *c, char specifier)
{
	const char      *format;
	size_t          idx;
	long		tmp;

	init_flag(f, specifier);
	format = c->format;
	idx = 1;
	while (format[idx] == ' '|| format[idx] == '-'|| format[idx] == '0')
	{
		if (format[idx] == ' ')
			f->space = 1;
		if (format[idx] == '0')
			f->zero = 1;
		if (format[idx] == '-')
			f->minus = 1;
		idx++;
	}
	if (format[idx] == '*')
	{
		tmp = va_arg(c->ap, int);
		if (tmp < 0)
		{
			f->minus = 1;
			tmp *= -1;
		}
		f->width = tmp;
		idx++;
	}
	else
	{
		f->width = ft_atoi(&format[idx]);
		while (ft_isdigit(format[idx]))
			idx++;
	}
	if (format[idx] == '.')
	{
		idx++;
		f->precision_exist = 1;
		if (format[idx] == '*')
		{
			tmp = va_arg(c->ap, int);
			if (tmp < 0)
				f->precision_exist = 0;
			else
				f->precision = tmp;
			idx++;
		}
		else
		{
			f->precision = ft_atoi(&format[idx]);
			while (ft_isdigit(format[idx]))
				idx++;
		}
	}
	if (format[idx] != specifier)
		return (-1);
	return (1);
}
