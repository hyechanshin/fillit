/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vniemi <vniemi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 18:10:02 by vniemi            #+#    #+#             */
/*   Updated: 2019/11/03 17:33:20 by vniemi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_create_nbr(int n, int neg)
{
	if (neg)
		ft_putchar('-');
	if (n >= 10)
		ft_putnbr(n / 10);
	ft_putchar((n % 10) + '0');
}

void		ft_putnbr(int n)
{
	int		neg;

	neg = 0;
	if (n == 0)
	{
		ft_putstr("0\0");
		return ;
	}
	if (n == -2147483648)
	{
		ft_putstr("-2147483648\0");
		return ;
	}
	if (n < 0)
	{
		neg = 1;
		n = -n;
	}
	ft_create_nbr(n, neg);
}
