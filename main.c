/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vniemi <vniemi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 14:08:43 by vniemi            #+#    #+#             */
/*   Updated: 2019/12/31 16:09:21 by vniemi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>

static int		fillit(t_dllist **tetrominos)
{
	t_board		*b;

	b = solve(*tetrominos);
	print_solution(b, *tetrominos, 0, 0);
	free_board(b);
	free_tetrominos(*tetrominos);
	return (1);
}

static int		read_file(int fd, char *buf, char tet_letter)
{
	int			ret;
	t_tetromino	*t;
	t_dllist	*tetrominos;
	int			has_nl;

	has_nl = 0;
	t = NULL;
	tetrominos = NULL;
	while ((ret = read(fd, buf, 21)))
	{
		t = find_tetromino(buf, tet_letter, 0, 0);
		if (t == NULL)
		{
			free_tetrominos(tetrominos);
			return (ERROR);
		}
		dllst_insert_at_end(&tetrominos, t);
		tet_letter++;
		has_nl = (buf[20] == '\n') ? 1 : 0;
		ft_bzero(buf, 21);
	}
	if (has_nl || dllst_get_size(tetrominos) == 0)
		return (ERROR);
	return (fillit(&tetrominos));
}

int				main(int argc, char *argv[])
{
	int		fd;
	char	*filename;
	char	*buf;

	if (argc != 2)
	{
		ft_putstr("usage: fillit file\n");
		return (1);
	}
	filename = argv[1];
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_putstr("error\n");
	else
	{
		buf = ft_strnew(21);
		if (ERROR == (read_file(fd, buf, 'A')))
			ft_putstr("error\n");
		free(buf);
		if (close(fd) == -1)
			return (ERROR);
	}
	return (0);
}
