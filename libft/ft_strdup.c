/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kycho <kycho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 02:50:35 by kycho             #+#    #+#             */
/*   Updated: 2020/04/04 18:50:53 by kycho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	size_t	need_size;

	need_size = sizeof(char) * (ft_strlen(s1) + 1);
	if (!(dup = (char *)malloc(need_size)))
		return (NULL);
	ft_strlcpy(dup, s1, need_size);
	return (dup);
}
