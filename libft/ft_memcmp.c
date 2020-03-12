/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kycho <kycho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 23:15:32 by kycho             #+#    #+#             */
/*   Updated: 2020/02/27 23:40:46 by kycho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t idx;
	int diff;

	idx = 0;
	while (idx < n)
	{
		diff = ((unsigned char *)s1)[idx] - ((unsigned char *)s2)[idx];
		if (diff != 0)
			return (diff);
		idx++;
	}
	return (0);
}
