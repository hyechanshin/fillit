/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vniemi <vniemi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 19:09:01 by vniemi            #+#    #+#             */
/*   Updated: 2019/11/26 19:10:41 by vniemi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dup;
	size_t	length;
	size_t	i;

	length = ft_strlen(src);
	if ((dup = (char*)malloc((length + 1) * sizeof(char))))
	{
		i = 0;
		while (src[i])
		{
			dup[i] = src[i];
			i++;
		}
		dup[i] = '\0';
		return (dup);
	}
	else
	{
		return (0);
	}
}
