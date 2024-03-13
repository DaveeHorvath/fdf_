/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:44:48 by dhorvath          #+#    #+#             */
/*   Updated: 2023/11/13 13:37:02 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!new || !lst)
		return ;
	last = ft_lstlast(*lst);
	if (last)
		last->next = new;
	else
		*lst = new;
}
/*
int main(void)
{
	t_list	*first;
	t_list	*second;
	t_list	*lst;

	lst = 0;
	first = ft_lstnew((void	*) ft_strdup("dumb"));
	second = ft_lstnew((void *) ft_strdup("dumber"));

	ft_lstadd_back(&lst, first);
	ft_lstadd_back(&lst, second);
}
*/