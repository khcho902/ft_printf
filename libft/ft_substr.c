/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kycho <kycho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 16:08:30 by kycho             #+#    #+#             */
/*   Updated: 2020/02/29 16:44:47 by kycho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char *substr;
	size_t s_len;
	size_t substr_len;

	s_len = ft_strlen(s);
	substr_len = 0;
	if (s_len > start)
		substr_len = (s_len - start < len) ? s_len - start : len;
	substr = (char *)malloc(sizeof(char)*(substr_len + 1));
	if (substr == NULL)
		return (NULL);
	ft_strlcpy(substr, s + start, substr_len + 1);
	return (substr);
}
