/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vniemi <vniemi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 18:06:54 by vniemi            #+#    #+#             */
/*   Updated: 2019/11/03 17:35:02 by vniemi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_create_string(int i, int n, char *num, int neg)
{
	while (i > 0)
	{
		num[i - 1] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	if (neg)
		num[0] = '-';
	return (num);
}

char		*ft_itoa(int n)
{
	char	*num;
	int		i;
	int		neg;

	i = 0;
	neg = 0;
	if (n < 0)
	{
		neg = 1;
		n = -n;
	}
	i = ft_countdigits(n);
	i += neg;
	if (!(num = (char *)ft_memalloc((sizeof(char)) * i + 1)))
		return (NULL);
	if (n == 0)
	{
		num[0] = 48;
		return (num);
	}
	if (n == -2147483648)
	{
		return (ft_strcpy(num, "-2147483648"));
	}
	return (ft_create_string(i, n, num, neg));
}
