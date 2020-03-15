/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_handler.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kycho <kycho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 21:03:31 by kycho             #+#    #+#             */
/*   Updated: 2020/03/15 19:40:33 by kycho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	is_in_set(char ch, const char *set)
{
	size_t idx;

	idx = 0;
	while (set[idx] != '\0')
	{
		if (set[idx] == ch)
			return (1);
		idx++;
	}
	return (0);
}


// 나중에 필요 없을듯 
size_t	get_conversion_len(const char *format)
{
	size_t len;

	len = 1;
	while (format[len])
	{
		if (is_in_set(format[len], FT_PRINTF_SPECIFIERS))
			return (len + 1);	
		len++;
	}
	return (len); // 에러가 나야하는 상황임
}


char 	get_specifier(const char *format, const char *specifiers)
{
	size_t idx;

	idx = 1;
	while (format[idx])
	{
		if (is_in_set(format[idx], specifiers))
			break;
		idx++;
	}
	return (format[idx]);
}

void	init_flag(t_printf_flag *flag)
{
	flag->space = 0;
	flag->zero = 0;
	flag->minus = 0;
	flag->width = 0;
	flag->precision_exist = 0;
	flag->precision = 0;
}

int	set_flag(t_printf_flag *f, t_printf_condition *c, char specifier)
{	
	const char	*format;
	size_t		idx;

	init_flag(f);
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
		f->width = va_arg(c->ap, int);
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
			f->precision = va_arg(c->ap, int);
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


int	ft_conversion_handler(t_printf_condition *condition, char *specifiers)
{
	char specifier;
	t_printf_flag flag;

	if (!(specifier = get_specifier(condition->format, specifiers)))
	{
		printf("\nspecifier error\n");
		return (-1);
	}
	if (set_flag(&flag, condition, specifier) == -1)
	{
		printf("\nflag error\n");
		return (-1);
	}

	printf("\nspace           : %d\n", flag.space);
	printf("zero            : %d\n", flag.zero);
	printf("minus           : %d\n", flag.minus);
	printf("width           : %d\n", flag.width);
	printf("precision_exist : %d\n", flag.precision_exist);
	printf("precision       : %d\n", flag.precision);
	printf("specifier       : %c\n", specifier);
		
	
	size_t len;
	len = get_conversion_len(condition->format);
	condition->format += len;
	for(int i = 0; i<len; i++)
		write(1, "@", 1);
	
	return (1);
}
