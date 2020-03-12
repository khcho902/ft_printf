/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putchar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kycho <kycho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 22:54:37 by kycho             #+#    #+#             */
/*   Updated: 2020/03/12 22:59:26 by kycho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_putchar(t_printf_condition *condition)
{
	ft_putchar_fd(condition->format[condition->idx], condition->fd);
	condition->idx++;
	condition->written_cnt++;
}
