/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vniemi <vniemi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 18:16:40 by vniemi            #+#    #+#             */
/*   Updated: 2019/11/01 21:59:39 by vniemi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int pos;
	unsigned int i;

	if (!*little)
		return ((char*)big);
	pos = 0;
	while (big[pos] != '\0' && (size_t)pos < len)
	{
		if (big[pos] == little[0])
		{
			i = 1;
			while (little[i] != '\0' && big[pos + i] == little[i] &&
					(size_t)(pos + i) < len)
				++i;
			if (little[i] == '\0')
				return ((char*)&big[pos]);
		}
		++pos;
	}
	return (0);
}
