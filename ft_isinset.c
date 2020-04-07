/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isinset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kycho <kycho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 20:18:33 by kycho             #+#    #+#             */
/*   Updated: 2020/04/07 12:57:48 by kycho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isinset(char ch, const char *set)
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
