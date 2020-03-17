/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_converter_pointer.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kycho <kycho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 22:02:57 by kycho             #+#    #+#             */
/*   Updated: 2020/03/17 23:23:07 by kycho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	get_number_len(size_t number)
{
	size_t len;

	if (number == 0)
		return (1);
	len = 0;
	while (number != 0)
	{
		number /= 16;
		len++;
	}
	return (len);
}

char	get_hex_char(int num)
{
	if (num < 10)
		return (num + '0');
	else
		return ('a' + num - 10);
}

char	*itoa_hex(size_t number)
{
	char *res;
	size_t number_len;

	number_len = get_number_len(number);
	res = (char *)malloc(sizeof(char) * (number_len + 1));
	res[number_len] = '\0';
	res[0] = '0';
	number_len--;
	while (number != 0)
	{
		res[number_len] = get_hex_char(number % 16);
		number /= 16;
		number_len--;
	}
	return (res);
}

char	*ft_printf_converter_pointer(t_printf_condition *c, t_printf_flag *f)
{
	char *res_str;
	size_t res_str_len;
	void *pointer;
	char *pointer_str;
	size_t pointer_str_len;
	size_t idx;

	if (f->zero || f->space || f->precision_exist)
		return (NULL);
	pointer = va_arg(c->ap, void *);
	pointer_str = itoa_hex((size_t)pointer);
	pointer_str_len = ft_strlen(pointer_str);
	res_str_len = pointer_str_len + 2;
	res_str_len = (f->width > res_str_len) ? f->width : res_str_len;
	res_str = (char *)malloc(sizeof(char) *(res_str_len + 1));
	res_str[res_str_len] = '\0';
	idx = (f->minus != 0) ? 2 : res_str_len - pointer_str_len;
	ft_memset(res_str, ' ', res_str_len);
	ft_memcpy(&res_str[idx], pointer_str, pointer_str_len);
	res_str[idx - 2] = '0';
	res_str[idx - 1] = 'x';

//	printf("pointer_str : %s\n", pointer_str);
//	printf("res_str : %s\n", res_str);
	/*	
	char *str;
	str = malloc(5);
	str[0] = 'a';
	str[1] = 'a';
	str[2] = 'a';
	str[3] = 'a';
	str[4] = '\0';

	return (str);
	*/
	free(pointer_str);
	return (res_str);
}
