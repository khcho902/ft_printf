/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kycho <kycho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 20:15:08 by kycho             #+#    #+#             */
/*   Updated: 2020/04/04 18:52:16 by kycho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t null_idx;
	size_t idx;

	null_idx = ft_strlen(s);
	idx = 0;
	while (idx <= null_idx)
	{
		if (s[null_idx - idx] == (char)c)
			return ((char *)s + null_idx - idx);
		idx++;
	}
	return (NULL);
}
