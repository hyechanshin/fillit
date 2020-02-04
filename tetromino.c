/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetromino.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vniemi <vniemi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 14:53:00 by vniemi            #+#    #+#             */
/*   Updated: 2019/12/31 15:56:21 by vniemi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				check_points(int num)
{
	if (num == 100102030 ||
		num == 100100111 ||
		num == 100010212 ||
		num == 100102001 ||
		num == 100101112 ||
		num == 120011121 ||
		num == 110110212 ||
		num == 100010203 ||
		num == 100011121 ||
		num == 100100102 ||
		num == 100102021 ||
		num == 110011121 ||
		num == 100011102 ||
		num == 100102011 ||
		num == 110011112 ||
		num == 110200111 ||
		num == 100011112 ||
		num == 100101121 ||
		num == 110011102)
		return (TRUE);
	else
		return (FALSE);
}

int				is_tetromino(t_dllist *list)
{
	t_dllist	*iterator;
	t_point		*point;
	int			num;

	num = 1;
	point = NULL;
	if (dllst_get_size(list) != 4)
		return (ERROR);
	iterator = list;
	while (iterator != NULL)
	{
		point = (t_point *)(iterator->content);
		num *= 10;
		num += point->x;
		num *= 10;
		num += point->y;
		iterator = iterator->next;
	}
	return (check_points(num));
}

void			normalize_shape(t_dllist *list)
{
	int			smallest_x;
	int			smallest_y;
	t_dllist	*iterator;
	t_point		*point;

	smallest_x = LARGEST_INT;
	smallest_y = LARGEST_INT;
	iterator = list;
	while (iterator != NULL)
	{
		point = (t_point *)(iterator->content);
		if (smallest_x > point->x)
			smallest_x = point->x;
		if (smallest_y > point->y)
			smallest_y = point->y;
		iterator = iterator->next;
	}
	iterator = list;
	while (iterator != NULL)
	{
		point = (t_point *)(iterator->content);
		point->x = point->x - smallest_x;
		point->y = point->y - smallest_y;
		iterator = iterator->next;
	}
}

t_tetromino		*make_tetromino(t_dllist *points, char letter)
{
	t_point		*point;
	t_point		*size;
	t_dllist	*iterator;
	t_tetromino *tet;
	int			i;

	size = get_tetronimo_size(points);
	tet = create_tetromino(size->x, size->y);
	tet->shape = (int **)ft_memalloc(sizeof(int *) * size->y);
	i = 0;
	while (i < size->y)
	{
		tet->shape[i] = (int *)ft_memalloc(sizeof(int *) * size->x);
		i++;
	}
	free(size);
	iterator = points;
	while (iterator != NULL)
	{
		point = (t_point *)(iterator->content);
		tet->shape[point->y][point->x] = 1;
		iterator = iterator->next;
	}
	tet->letter = letter;
	return (tet);
}
