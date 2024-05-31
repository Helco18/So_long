/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcannaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:07:26 by gcannaud          #+#    #+#             */
/*   Updated: 2023/11/07 17:39:41 by gcannaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	n;
	size_t	m;

	n = 0;
	m = 0;
	if (!s1 || !s2)
		return (0);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (s1[n])
	{
		str[n] = s1[n];
		n++;
	}
	while (n < (ft_strlen(s1) + ft_strlen(s2)))
	{
		str[n] = s2[m];
		m++;
		n++;
	}
	str[n] = 0;
	return (str);
}
