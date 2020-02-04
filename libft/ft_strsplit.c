/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vniemi <vniemi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 18:02:47 by vniemi            #+#    #+#             */
/*   Updated: 2019/11/05 22:12:57 by vniemi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_readwords(char const *s, char c, char **words)
{
	int		i;
	int		reading;
	int		beginning;
	int		word;

	beginning = 0;
	reading = 0;
	word = 0;
	i = 0;
	while (word < ft_countwords(s, c))
	{
		if (s[i] != c && reading == 0)
		{
			reading = 1;
			beginning = i;
		}
		if ((s[i] == c || s[i] == '\0') && reading == 1)
		{
			reading = 0;
			words[word] = ft_strsub(s, beginning, i - beginning);
			word++;
		}
		i++;
	}
	return (words);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**words;

	if (!s)
		return (NULL);
	if (!(words = (char **)ft_memalloc((ft_countwords(s, c) + 1) *
		sizeof(char *))))
	{
		free(words);
		return (NULL);
	}
	return (ft_readwords(s, c, words));
}
