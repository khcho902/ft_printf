/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_conversion_char.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kycho <kycho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 22:34:06 by kycho             #+#    #+#             */
/*   Updated: 2020/03/07 22:40:24 by kycho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_is_conversion_char(char ch)
{
	size_t idx;
	char *conversions;

	idx = 0;
	while (conversions[idx])
	{
		if (conversions[idx] == ch)
			return (TRUE);
		idx++;
	}
	return (FALSE);
}
