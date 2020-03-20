/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_converter_percent.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kycho <kycho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 22:32:41 by kycho             #+#    #+#             */
/*   Updated: 2020/03/20 22:38:40 by kycho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_printf_converter_percent(t_printf_condition *c, t_printf_flag *f)
{
	char *res;

	if (c == NULL || f == NULL)
		return (NULL);
	res = (char *)malloc(sizeof(char) * 2);
	if (res == NULL)
		return (NULL);
	res[0] = '%';
	res[1] = '\0';
	return (res);
}
