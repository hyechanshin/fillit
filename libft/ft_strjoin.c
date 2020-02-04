/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vniemi <vniemi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 18:00:53 by vniemi            #+#    #+#             */
/*   Updated: 2019/11/26 19:09:13 by vniemi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1length;
	size_t	s2length;
	char	*newstring;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1length = ft_strlen(s1);
	s2length = ft_strlen(s2);
	if (!(newstring = ft_strnew(s1length + s2length + 1)))
		return (NULL);
	ft_strcpy(newstring, s1);
	ft_strcat(newstring, s2);
	return (newstring);
}
