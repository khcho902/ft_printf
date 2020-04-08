/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_handler.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kycho <kycho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 21:03:31 by kycho             #+#    #+#             */
/*   Updated: 2020/04/09 00:33:39 by kycho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	get_conversion_len(const char *format, char specifier)
{
	size_t len;

	len = 1;
	while (format[len] != specifier)
		len++;
	return (len + 1);
}

void	*get_converter(char specifier)
{
	if (specifier == 'c')
		return (&ft_printf_converter_char);
	else if (specifier == 's')
		return (&ft_printf_converter_string);
	else if (specifier == 'p')
		return (&ft_printf_converter_pointer);
	else if (specifier == 'd' || specifier == 'i')
		return (&ft_printf_converter_int);
	else if (specifier == 'u')
		return (&ft_printf_converter_unsigned_int);
	else if (specifier == 'x' || specifier == 'X')
		return (&ft_printf_converter_hex);
	else if (specifier == '%')
		return (&ft_printf_converter_percent);
	return (NULL);
}

int		ft_conversion_handler(t_printf_condition *condition, char *specifiers)
{
	char			specifier;
	t_printf_flag	flag;
	t_printf_res	result;
	t_converter		converter;

	if (!(specifier = ft_get_specifier(condition->format, specifiers)))
		return (-1);
	if (ft_set_flag(&flag, condition, specifier) == -1)
		return (-1);
	if (!(converter = get_converter(specifier)))
		return (-1);
	if (converter(condition, &flag, &result) == -1)
		return (-1);
	write(condition->fd, result.res, result.res_len);
	condition->format += get_conversion_len(condition->format, specifier);
	free(result.res);
	return (result.res_len);
}
