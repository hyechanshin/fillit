/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vniemi <vniemi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 21:29:51 by vniemi            #+#    #+#             */
/*   Updated: 2019/12/30 14:56:23 by vniemi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ceil_sqrt(int nbr)
{
	int size;

	size = 2;
	while (size * size < nbr)
		size++;
	return (size);
}

t_point	*get_tetronimo_size(t_dllist *list)
{
	t_dllist	*iterator;
	t_point		*point;
	int			width;
	int			height;

	width = 0;
	height = 0;
	iterator = list;
	while (iterator != NULL)
	{
		point = (t_point *)(iterator->content);
		if (point->x > width)
			width = point->x;
		if (point->y > height)
			height = point->y;
		iterator = iterator->next;
	}
	return (new_point(width + 1, height + 1));
}
