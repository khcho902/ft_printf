/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kycho <kycho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 20:48:47 by kycho             #+#    #+#             */
/*   Updated: 2020/04/04 18:52:50 by kycho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t idx;
	size_t haystack_len;
	size_t needle_len;

	needle_len = ft_strlen(needle);
	if (needle_len == 0)
		return ((char *)haystack);
	haystack_len = ft_strlen(haystack);
	if (len > haystack_len)
		len = haystack_len;
	idx = 0;
	while (idx + needle_len <= len)
	{
		if (ft_strncmp(haystack + idx, needle, needle_len) == 0)
			return ((char *)haystack + idx);
		idx++;
	}
	return (NULL);
}
