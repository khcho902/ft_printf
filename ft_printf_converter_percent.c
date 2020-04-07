/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_converter_percent.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kycho <kycho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 22:32:41 by kycho             #+#    #+#             */
/*   Updated: 2020/04/07 13:00:38 by kycho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_printf_converter_percent(t_printf_condition *c, t_printf_flag *f)
{
	char *res;

	if (c == NULL || f == NULL)
		return (NULL);
	f->res_len = 1;
	res = (char *)malloc(sizeof(char) * f->res_len);
	if (res == NULL)
		return (NULL);
	res[0] = '%';
	return (res);
}
