/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kycho <kycho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 19:31:32 by kycho             #+#    #+#             */
/*   Updated: 2020/04/04 18:50:19 by kycho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long n_long;

	n_long = (long)n;
	if (n_long < 0)
	{
		ft_putchar_fd('-', fd);
		n_long *= -1;
	}
	if (n_long >= 10)
		ft_putnbr_fd((int)(n_long / 10), fd);
	ft_putchar_fd(n_long % 10 + '0', fd);
}
