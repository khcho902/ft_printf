/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kycho <kycho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:34:04 by kycho             #+#    #+#             */
/*   Updated: 2020/04/04 18:49:53 by kycho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (src >= dst)
	{
		ft_memcpy(dst, src, len);
		return (dst);
	}
	while (len-- > 0)
	{
		((unsigned char *)dst)[len] = ((unsigned char *)src)[len];
	}
	return (dst);
}
