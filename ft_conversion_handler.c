/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_handler.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kycho <kycho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 21:03:31 by kycho             #+#    #+#             */
/*   Updated: 2020/03/15 21:17:16 by kycho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

size_t	get_conversion_len(const char *format)
{
	size_t len;

	len = 1;
	while (format[len])
	{
		if (ft_isinset(format[len], FT_PRINTF_SPECIFIERS))
			return (len + 1);	
		len++;
	}
	return (len); // 에러가 나야하는 상황임
}

void	*get_converter(char *specifier)
{
	if (specifier == 'c')
		return (&ft_printf_converter_char);
	return (NULL);
}

int	ft_conversion_handler(t_printf_condition *condition, char *specifiers)
{
	char specifier;
	t_printf_flag flag;
	void *converter;
	char *converted_res;

	if (!(specifier = ft_get_specifier(condition->format, specifiers)))
	{
		printf("\nspecifier error\n");
		return (-1);
	}
	if (ft_set_flag(&flag, condition, specifier) == -1)
	{
		printf("\nflag error\n");
		return (-1);
	}

	converter = get_converter(specifier);
	converted_res = run_converter(flag, condition, converter);



	/*
	printf("\nspace           : %d\n", flag.space);
	printf("zero            : %d\n", flag.zero);
	printf("minus           : %d\n", flag.minus);
	printf("width           : %d\n", flag.width);
	printf("precision_exist : %d\n", flag.precision_exist);
	printf("precision       : %d\n", flag.precision);
	printf("specifier       : %c\n", specifier);
	*/	
	
	size_t len;
	len = get_conversion_len(condition->format);
	condition->format += len;
	/*
	for(int i = 0; i<len; i++)
		write(1, "@", 1);
	*/
	return (1);
}
