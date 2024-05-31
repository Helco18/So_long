/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcannaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:26:33 by gcannaud          #+#    #+#             */
/*   Updated: 2023/11/07 21:39:17 by gcannaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int cm, size_t n)
{
	char	*cs;
	size_t	len;
	int		i;

	i = 0;
	len = 0;
	cs = (char *)s;
	while (len < n)
	{
		if (cs[i] == (char)cm)
			return ((void *)&cs[i]);
		i++;
		len++;
	}
	return (0);
}
