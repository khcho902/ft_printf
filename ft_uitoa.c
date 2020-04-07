/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kycho <kycho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 22:55:26 by kycho             #+#    #+#             */
/*   Updated: 2020/04/07 14:07:38 by kycho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	get_n_len(unsigned int n)
{
	size_t len;

	if (n == 0)
		return (1);
	len = 0;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char			*ft_uitoa(unsigned int n)
{
	char	*res;
	size_t	len;

	len = get_n_len(n);
	if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	res[0] = '0';
	res[len] = '\0';
	len--;
	while (n != 0)
	{
		res[len] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	return (res);
}
