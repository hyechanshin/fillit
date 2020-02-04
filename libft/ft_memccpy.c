/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vniemi <vniemi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 18:16:35 by vniemi            #+#    #+#             */
/*   Updated: 2019/11/01 20:19:19 by vniemi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	void *c2;

	if (!(c2 = ft_memchr(src, c, n)))
	{
		ft_memcpy(dest, src, n);
		return (NULL);
	}
	ft_memcpy(dest, src, c2 - src + 1);
	return (dest + (c2 - src + 1));
}
