/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcannaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 00:17:00 by gcannaud          #+#    #+#             */
/*   Updated: 2023/11/08 00:08:37 by gcannaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_malloctab(char const *s, char c)
{
	size_t	count;
	int		i;

	count = 0;
	i = 0;
	if (s[0] != c && s[0] != 0)
		count++;
	while (s[i])
	{
		if (s[i] == c && (s[i + 1] != c) && (s[i + 1] != 0))
			count++;
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;

	j = 0;
	if (!s)
		return (NULL);
	tab = malloc(sizeof(char *) * (ft_malloctab(s, c) + 1));
	if (!tab)
		return (NULL);
	while (*s)
	{
		if (s[0] == c)
			s++;
		else
		{
			i = 0;
			while (s[i] != c && s[i] != 0)
				i++;
			tab[j++] = ft_substr(s, 0, i);
			s = s + i;
		}
	}
	tab[j] = NULL;
	return (tab);
}
