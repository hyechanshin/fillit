/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vniemi <vniemi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 21:28:46 by vniemi            #+#    #+#             */
/*   Updated: 2019/12/31 15:44:42 by vniemi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			fill_board(t_board *b, t_dllist *list)
{
	int			i;
	int			j;
	t_tetromino	*tet;

	if (list == NULL)
		return (1);
	i = 0;
	tet = (t_tetromino *)(list->content);
	while (i < b->size - tet->height + 1)
	{
		j = 0;
		while (j < b->size - tet->width + 1)
		{
			if (add_tetromino(b, tet, point(j, i), 1))
			{
				if (fill_board(b, list->next))
					return (1);
				else
					add_tetromino(b, tet, point(j, i), 0);
			}
			j++;
		}
		i++;
	}
	return (0);
}

t_board		*solve(t_dllist *list)
{
	t_board	*b;
	int		size;
	int		num_of_nodes;

	num_of_nodes = dllst_get_size(list);
	size = ceil_sqrt(num_of_nodes * 4);
	b = create_board(size);
	while (!fill_board(b, list))
	{
		size++;
		free_board(b);
		b = create_board(size);
	}
	return (b);
}

int			find_points(char *str, t_dllist **points, int x, int y)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '.' && str[i] != '#' && str[i] != '\n')
			return (ERROR);
		if (str[i] == '#')
			dllst_insert_at_end(&(*points), new_point(x, y));
		x++;
		if (str[i] == '\n')
		{
			if (x != 1 && x != 5)
				return (ERROR);
			x = 0;
			y++;
		}
		i++;
	}
	if ((y != 5 && y != 4) || str[0] == '\n')
		return (ERROR);
	return (1);
}

t_tetromino	*find_tetromino(char *str, char tet_letter, int x, int y)
{
	t_dllist	*points;
	t_tetromino	*t;

	points = NULL;
	t = NULL;
	if (find_points(str, &points, x, y))
	{
		normalize_shape(points);
		if (is_tetromino(points) == FALSE)
		{
			free_points(points);
			return (ERROR);
		}
		t = make_tetromino(points, tet_letter);
	}
	free_points(points);
	return (t);
}
