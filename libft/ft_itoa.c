/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kycho <kycho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 20:55:16 by kycho             #+#    #+#             */
/*   Updated: 2020/02/29 22:06:59 by kycho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_n_len(int n)
{
	size_t len;
	size_t minus;

	if (n == 0)
		return (1);
	minus = (n < 0) ? 1 : 0;
	len = 0;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (minus + len);
}

char	*ft_itoa(int n)
{
	char	*res;
	size_t	len;
	
	len = get_n_len(n);
	if(!(res = (char *)malloc(sizeof(char)*(len + 1))))
		return (NULL);
	res[0] = (n < 0) ? '-' : '0';
	res[len] = '\0';
	len--;
	while (n != 0)
	{
		res[len] = (n % 10 < 0) ? -1 * (n % 10) + '0' : (n % 10) + '0';
		n /= 10;
		len--;
	}
	return (res);
}
