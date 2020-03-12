/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_handler.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kycho <kycho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 21:03:31 by kycho             #+#    #+#             */
/*   Updated: 2020/03/13 01:12:18 by kycho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	is_in_set(char ch, char *set)
{
	size_t idx;

	idx = 0;
	while (set[idx] != '\0')
	{
		if (set[idx] == ch)
			return (TRUE);
		idx++;
	}
	return (FALSE);
}

static size_t	get_conversion_len(const char *format)
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

void	ft_conversion_handler(t_printf_condition *condition)
{
	size_t len;

	len = get_conversion_len(condition->format);
	condition->format += len;

	for(int i = 0; i<len; i++)
		write(1, "@", 1);
}
