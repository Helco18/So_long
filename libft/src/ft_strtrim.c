/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcannaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:48:22 by gcannaud          #+#    #+#             */
/*   Updated: 2023/11/07 18:24:38 by gcannaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	sim(char const *s1, char const *set, int i)
{
	int	j;

	j = 0;
	while (s1[i] != set[j] && set[j] != 0)
	{
		j++;
		if (s1[i] == set[j])
			return (1);
	}
	if (s1[i] == set[j])
		return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		c;
	size_t	size;

	j = 0;
	i = 0;
	c = 0;
	if (!s1)
		return (0);
	while (sim(s1, set, i) && (size_t)i < ft_strlen(s1))
		i++;
	while (s1[j])
		j++;
	while (sim(s1, set, j) && j >= 0)
		j--;
	c = j - i;
	c++;
	size = c;
	return (ft_substr(s1, i, c));
}
