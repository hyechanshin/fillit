/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vniemi <vniemi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 18:02:08 by vniemi            #+#    #+#             */
/*   Updated: 2019/11/03 17:34:35 by vniemi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_whitespace(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

char		*ft_strtrim(char const *s)
{
	int spaces_end;
	int spaces_beginning;
	int length;
	int i;

	if (!s)
		return (0);
	i = 0;
	spaces_end = 0;
	spaces_beginning = 0;
	length = ft_strlen((char *)s);
	while (ft_is_whitespace(s[i++]))
	{
		spaces_beginning++;
	}
	if (spaces_beginning == length)
		return (ft_strnew(0));
	i = length - 1;
	while (ft_is_whitespace(s[i--]))
	{
		spaces_end++;
	}
	return (ft_strsub(s, spaces_beginning, length - spaces_beginning
	- spaces_end));
}
