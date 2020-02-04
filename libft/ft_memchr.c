/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vniemi <vniemi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 15:22:06 by vniemi            #+#    #+#             */
/*   Updated: 2019/11/05 22:10:54 by vniemi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	uc;
	unsigned char	*ptr;

	i = 0;
	uc = (unsigned char)c;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		if (*ptr == uc)
		{
			return (ptr);
		}
		i++;
		ptr++;
	}
	return (NULL);
}
