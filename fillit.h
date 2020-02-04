/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vniemi <vniemi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 20:01:42 by vniemi            #+#    #+#             */
/*   Updated: 2019/12/31 16:03:16 by vniemi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define TRUE 1
# define FALSE 0
# define ERROR 0
# define LARGEST_INT 2147483647
# include "libft/libft.h"

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_board
{
	int				size;
	int				**shape;
}					t_board;

typedef struct		s_tetromino
{
	int				width;
	int				height;
	char			letter;
	char			*color;
	int				**shape;
	t_point			pos;
}					t_tetromino;

typedef struct		s_dllist
{
	void			*content;
	int				key;
	struct s_dllist	*next;
	struct s_dllist	*previous;
}					t_dllist;

/*
**dllst
*/
void				dllst_reverse_list(t_dllist **head);
void				dllst_insert_at_end(t_dllist **phead, void *value);
void				dllst_insert_at_front(t_dllist **phead, void *value);
void				dllst_free_list(t_dllist *node);
int					dllst_get_size(t_dllist *head);

/*
** print
*/
void				print_cell_letter(t_tetromino *tet, int j, int i);
void				print_solution(t_board *board,
	t_dllist *head, int i, int j);

/*
** free data
*/
void				free_board(t_board *b);
void				free_tetrominos(t_dllist *head);
void				free_points(t_dllist *head);

/*
** point2d
*/
t_point				point(int x, int y);
t_point				*new_point(int x, int y);
int					point_is_equal(t_point point1, t_point point2);

/*
** math
*/
int					ceil_sqrt(int nbr);
t_point				*get_tetronimo_size(t_dllist *list);

/*
** board
*/
t_tetromino			*create_tetromino(int width, int height);
t_board				*create_board(int size);
int					fill_board(t_board *b, t_dllist *list);
t_board				*solve(t_dllist *list);
t_point				*get_size(t_dllist *list);

/*
** tetromino
*/
int					is_tetromino(t_dllist *list);
int					check_points(int num);
void				normalize_shape(t_dllist *list);
t_tetromino			*make_tetromino(t_dllist *points, char letter);
int					is_colliding(t_board *board, t_tetromino *tet, t_point pos);

/*
** solver
*/
int					is_colliding(t_board *board, t_tetromino *tet, t_point pos);
int					is_overboard(t_board *board, t_tetromino *tet, t_point pos);
int					add_tetromino(t_board *board,
	t_tetromino *tet, t_point pos, int num);
int					find_points(char *str, t_dllist **points, int x, int y);
t_tetromino			*find_tetromino(char *str, char tet_letter, int x, int y);

#endif
