/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kycho <kycho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 23:34:34 by kycho             #+#    #+#             */
/*   Updated: 2020/04/04 18:47:47 by kycho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t idx;

	idx = 0;
	while (idx < n)
	{
		((unsigned char *)dst)[idx] = ((unsigned char *)src)[idx];
		if (((unsigned char *)src)[idx] == (unsigned char)c)
			return (dst + idx + 1);
		idx++;
	}
	return (NULL);
}
