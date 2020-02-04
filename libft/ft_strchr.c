/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vniemi <vniemi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 17:05:03 by vniemi            #+#    #+#             */
/*   Updated: 2019/11/02 15:53:47 by vniemi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char *buffer;

	buffer = (char *)s;
	if ((char)c == '\0')
		return (buffer + ft_strlen(s));
	while (*buffer != '\0')
	{
		if (*buffer == c)
		{
			return (buffer);
		}
		buffer++;
	}
	return (NULL);
}
