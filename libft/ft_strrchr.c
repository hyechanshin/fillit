/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vniemi <vniemi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 17:05:03 by vniemi            #+#    #+#             */
/*   Updated: 2019/11/26 19:11:47 by vniemi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*buffer;
	size_t	length;

	buffer = (char *)s;
	if ((char)c == '\0')
		return (buffer + ft_strlen(s));
	length = ft_strlen(buffer);
	while (length--)
	{
		if (*(buffer + length) == c)
		{
			return (buffer + length);
		}
	}
	return (NULL);
}
