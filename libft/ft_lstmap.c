/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kycho <kycho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 22:42:33 by kycho             #+#    #+#             */
/*   Updated: 2020/03/04 22:52:29 by kycho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *new_first_lst;
	t_list *new_lst;

	if (!lst || !f || !del)
		return (NULL);

	if (!(new_first_lst = ft_lstnew(f(lst->content))))
		return (NULL);
	new_lst = new_first_lst;

	while (lst->next)
	{
		lst = lst->next;
		if (!(new_lst->next = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&new_first_lst, del);
			return (NULL);
		}
		new_lst = new_lst->next;
	}
	return (new_first_lst);
}
