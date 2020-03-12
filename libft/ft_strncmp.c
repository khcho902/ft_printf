/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kycho <kycho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 22:53:54 by kycho             #+#    #+#             */
/*   Updated: 2020/02/28 23:43:35 by kycho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t idx;

	if (n == 0)
		return (0);
	idx = 0;
	while (idx < n && s1[idx] && s2[idx] && s1[idx] == s2[idx])
		idx++;
	if (idx == n)
		return (0);
	return ((unsigned char)s1[idx] - (unsigned char)s2[idx]);
}
