/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vniemi <vniemi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 18:15:23 by vniemi            #+#    #+#             */
/*   Updated: 2019/11/03 17:34:49 by vniemi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_create_nbr_fd(int n, int neg, int fd)
{
	if (neg)
		ft_putchar_fd('-', fd);
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd((n % 10) + '0', fd);
}

void		ft_putnbr_fd(int n, int fd)
{
	int		neg;

	neg = 0;
	if (n == 0)
	{
		ft_putstr_fd("0\0", fd);
		return ;
	}
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648\0", fd);
		return ;
	}
	if (n < 0)
	{
		neg = 1;
		n = -n;
	}
	ft_create_nbr_fd(n, neg, fd);
}
