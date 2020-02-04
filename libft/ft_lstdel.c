/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vniemi <vniemi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 13:35:42 by vniemi            #+#    #+#             */
/*   Updated: 2019/11/05 22:10:08 by vniemi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *curr;
	t_list *list;

	curr = *alst;
	list = *alst;
	while (list)
	{
		curr = curr->next;
		del(list->content, list->content_size);
		free(list);
		list = curr;
	}
	*alst = NULL;
}
