/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kycho <kycho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 20:07:38 by kycho             #+#    #+#             */
/*   Updated: 2020/03/18 20:31:45 by kycho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_n_len(unsigned long n, size_t base_len)
{
	int n_len;

	if (n == 0)
		return (1);
	n_len = 0;
	while (n != 0)
	{
		n /= base_len;
		n_len++;
	}
	return (n_len);
}

char	*ft_ultoa_base(unsigned long n, char *base)
{
	char	*res;
	int	n_len;
	size_t	base_len;
	
	base_len = ft_strlen(base);
	n_len = get_n_len(n, base_len);
	res = (char *)malloc(sizeof(char)*(n_len + 1));
	if (res == NULL)
		return (NULL);
	res[n_len] = '\0';
	n_len--;
	while (n != 0)
	{
		res[n_len] = base[n % base_len];
		n /= base_len;
		n_len--;
	}
	return (res);
}
