/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kycho <kycho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 19:56:17 by kycho             #+#    #+#             */
/*   Updated: 2020/03/02 20:07:09 by kycho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *node;
	t_list *next;

	if (!lst || !del || !*lst)
		return ;
	node = *lst;
	next = node->next;
	while (node)
	{
		ft_lstdelone(node, del);
		node = next;
		if (node)
			next = node->next;
	}
	*lst = NULL;
}
