/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vniemi <vniemi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 13:35:43 by vniemi            #+#    #+#             */
/*   Updated: 2019/11/05 22:10:39 by vniemi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *newhead;
	t_list *newlst;
	t_list *newnode;

	if (!lst || !f)
		return (NULL);
	newnode = f(lst);
	if (!(newlst = ft_lstnew(newnode->content, newnode->content_size)))
	{
		return (NULL);
	}
	newhead = newlst;
	while ((lst = lst->next))
	{
		newnode = f(lst);
		if (!(newlst->next = ft_lstnew(newnode->content,
			newnode->content_size)))
		{
			return (NULL);
		}
		newlst = newlst->next;
	}
	return (newhead);
}
