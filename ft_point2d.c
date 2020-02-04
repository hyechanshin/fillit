/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point2d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyshin <kirikeria@gmai.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 21:04:47 by vniemi            #+#    #+#             */
/*   Updated: 2019/12/29 18:32:47 by hyshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_point		point(int x, int y)
{
	t_point		point;

	point.x = x;
	point.y = y;
	return (point);
}

t_point		*new_point(int x, int y)
{
	t_point		*p;

	p = ft_memalloc(sizeof(t_point));
	p->x = x;
	p->y = y;
	return (p);
}

int			point_is_equal(t_point point1, t_point point2)
{
	if (point1.x == point2.x && point1.y == point2.y)
		return (TRUE);
	return (FALSE);
}
