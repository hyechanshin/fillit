/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vniemi <vniemi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 15:22:25 by vniemi            #+#    #+#             */
/*   Updated: 2019/11/05 22:17:27 by vniemi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t num)
{
	unsigned char	*uptr;
	size_t			i;

	i = 0;
	uptr = (unsigned char*)ptr;
	while (i < num)
	{
		uptr[i] = (unsigned char)value;
		i++;
	}
	return (ptr);
}
