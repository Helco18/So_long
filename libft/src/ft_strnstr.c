/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcannaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:43:50 by gcannaud          #+#    #+#             */
/*   Updated: 2023/11/07 16:54:24 by gcannaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (len == 0 && !str)
		return (NULL);
	if (to_find[0] == 0)
		return ((char *)str);
	while (str[i])
	{
		j = 0;
		while (to_find[j] == str[i + j] && str[i + j] != 0 && i + j < len)
		{
			if (to_find[j + 1] == 0)
				return ((char *)&str[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
