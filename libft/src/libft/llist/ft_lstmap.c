/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:59:50 by dhorvath          #+#    #+#             */
/*   Updated: 2023/10/27 12:39:53 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*tmp;

	newlist = 0;
	while (lst)
	{
		tmp = ft_lstnew((*f)(lst->content));
		if (tmp == 0)
		{
			ft_lstclear(&newlist, del);
			return (0);
		}
		ft_lstadd_back(&newlist, tmp);
		lst = lst->next;
	}
	return (newlist);
}
