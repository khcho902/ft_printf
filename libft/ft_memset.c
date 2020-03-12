/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kycho <kycho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 22:09:27 by kycho             #+#    #+#             */
/*   Updated: 2020/02/27 00:33:48 by kycho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t idx;

	idx = 0;
	while (idx < len)
	{
		((unsigned char *)b)[idx] = (unsigned char)c;
		idx++;
	}
	return (b);
}
