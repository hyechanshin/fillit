/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyshin <kirikeria@gmai.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 20:16:38 by vniemi            #+#    #+#             */
/*   Updated: 2019/12/29 18:35:52 by hyshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_cell_letter(t_tetromino *tet, int j, int i)
{
	int x;
	int y;

	x = j - (tet->pos.x);
	y = i - (tet->pos.y);
	if (x >= 0 && x < tet->width && y >= 0 && y < tet->height &&
		tet->shape[y][x] == 1)
	{
		ft_putchar(tet->letter);
	}
}

void	print_solution(t_board *board, t_dllist *head, int i, int j)
{
	t_dllist	*iterator;

	while (i < board->size)
	{
		while (j < board->size)
		{
			if (board->shape[j][i] == 1)
			{
				iterator = head;
				while (iterator != NULL)
				{
					print_cell_letter(iterator->content, j, i);
					iterator = iterator->next;
				}
			}
			else
				ft_putchar('.');
			j++;
		}
		ft_putchar('\n');
		j = 0;
		i++;
	}
}
