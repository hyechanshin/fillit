/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vniemi <vniemi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 17:57:52 by vniemi            #+#    #+#             */
/*   Updated: 2019/11/01 21:34:13 by vniemi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*newstr;

	i = 0;
	if (!s || !f)
		return (NULL);
	if (!(newstr = ft_memalloc(ft_strlen((char *)s) + 1)))
		return (NULL);
	while (s[i] != '\0')
	{
		newstr[i] = f(s[i]);
		i++;
	}
	return (newstr);
}
