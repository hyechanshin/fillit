/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vniemi <vniemi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 14:40:01 by vniemi            #+#    #+#             */
/*   Updated: 2019/12/31 16:01:52 by vniemi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			is_colliding(t_board *board, t_tetromino *tet, t_point pos)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < tet->width)
	{
		while (j < tet->height)
		{
			if (tet->shape[j][i] == 1 && board->shape[i + pos.x][j + pos.y]
			== 1)
				return (TRUE);
			j++;
		}
		j = 0;
		i++;
	}
	return (FALSE);
}

int			add_tetromino(t_board *board
	, t_tetromino *tet, t_point pos, int num)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (num != 0 && (is_colliding(board, tet, pos)))
		return (0);
	tet->pos = pos;
	while (i < tet->height)
	{
		while (j < tet->width)
		{
			if (tet->shape[i][j] == 1)
				board->shape[j + tet->pos.x][i + tet->pos.y] = num;
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

t_tetromino	*create_tetromino(int width, int height)
{
	t_tetromino *tet;

	tet = (t_tetromino *)ft_memalloc(sizeof(t_tetromino));
	tet->width = width;
	tet->height = height;
	tet->pos = point(0, 0);
	return (tet);
}

t_board		*create_board(int size)
{
	t_board	*b;
	int		i;

	b = (t_board *)ft_memalloc(sizeof(t_board));
	b->size = size;
	b->shape = (int **)ft_memalloc(sizeof(int *) * size);
	i = 0;
	while (i < size)
	{
		b->shape[i] = (int *)ft_memalloc(sizeof(int *) * size);
		i++;
	}
	return (b);
}
