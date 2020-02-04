/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vniemi <vniemi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 13:57:35 by vniemi            #+#    #+#             */
/*   Updated: 2019/11/02 14:03:54 by vniemi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprint(t_list *head)
{
	t_list *curr;

	curr = head;
	while (curr != NULL)
	{
		ft_putstr(curr->content);
		if (curr->next != NULL)
			ft_putstr("->");
		curr = curr->next;
	}
}
