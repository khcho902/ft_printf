/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kycho <kycho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 22:08:07 by kycho             #+#    #+#             */
/*   Updated: 2020/02/29 22:45:43 by kycho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	size_t	idx;
	size_t	len;
	
	len = ft_strlen(s);
	if(!(res = (char *)malloc(sizeof(char)*(len + 1))))
		return (NULL);
	idx = 0;
	while (idx < len)
	{
		res[idx] = f(idx, s[idx]);
		idx++;
	}
	res[idx] = '\0';
	return (res);
}
