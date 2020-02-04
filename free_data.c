/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vniemi <vniemi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 15:33:36 by vniemi            #+#    #+#             */
/*   Updated: 2019/12/29 23:27:07 by vniemi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

void	free_board(t_board *b)
{
	int	i;

	i = 0;
	while (i < b->size)
	{
		free(b->shape[i]);
		i++;
	}
	free(b->shape);
	free(b);
}

void	free_tetrominos(t_dllist *head)
{
	int			i;
	t_tetromino	*t;
	t_dllist	*iterator;

	iterator = head;
	while (iterator != NULL)
	{
		i = 0;
		t = (t_tetromino *)iterator->content;
		while (i < t->height)
		{
			free(t->shape[i]);
			i++;
		}
		iterator = iterator->next;
		free(t->shape);
		free(t);
	}
	dllst_free_list(head);
}

void	free_points(t_dllist *head)
{
	int			i;
	t_point		*p;
	t_dllist	*iterator;

	i = 0;
	iterator = head;
	while (iterator != NULL)
	{
		p = (t_point *)iterator->content;
		free(p);
		iterator = iterator->next;
	}
	dllst_free_list(head);
}
