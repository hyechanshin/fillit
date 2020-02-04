/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dllst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vniemi <vniemi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 21:15:29 by vniemi            #+#    #+#             */
/*   Updated: 2019/12/29 23:38:45 by vniemi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	dllst_insert_at_front(t_dllist **phead, void *value)
{
	t_dllist *curr;

	if (NULL == phead)
		return ;
	curr = malloc(sizeof(*curr));
	curr->next = NULL;
	curr->previous = NULL;
	curr->content = value;
	if (*phead == NULL)
	{
		*phead = curr;
		return ;
	}
	curr->next = *phead;
	(*phead)->previous = curr;
	*phead = curr;
}

void	dllst_insert_at_end(t_dllist **phead, void *value)
{
	t_dllist	*curr;
	t_dllist	*iterator;

	iterator = *phead;
	if (NULL == phead)
		return ;
	curr = malloc(sizeof(*curr));
	curr->content = value;
	curr->next = NULL;
	curr->previous = NULL;
	if (*phead == NULL)
	{
		*phead = curr;
		return ;
	}
	while (iterator->next != NULL)
		iterator = iterator->next;
	iterator->next = curr;
	curr->previous = iterator;
}

void	dllst_free_list(t_dllist *node)
{
	t_dllist *next;

	while (node != NULL)
	{
		next = node->next;
		free(node);
		node = next;
	}
}

void	dllst_reverse_list(t_dllist **head)
{
	t_dllist *iterator;
	t_dllist *previous;
	t_dllist *next;

	iterator = *head;
	previous = NULL;
	next = NULL;
	while (iterator != NULL)
	{
		next = iterator->next;
		iterator->next = previous;
		previous = iterator;
		iterator = next;
	}
}

int		dllst_get_size(t_dllist *head)
{
	t_dllist	*iterator;
	int			size;

	iterator = head;
	size = 0;
	while (iterator != NULL)
	{
		iterator = iterator->next;
		size++;
	}
	return (size);
}
