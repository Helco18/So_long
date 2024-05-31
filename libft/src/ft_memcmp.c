/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcannaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:01:09 by gcannaud          #+#    #+#             */
/*   Updated: 2023/11/02 15:18:27 by gcannaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			len;
	unsigned char	*cs1;
	unsigned char	*cs2;

	cs1 = (unsigned char *)s1;
	cs2 = (unsigned char *)s2;
	len = 0;
	while (n && (cs1[len] == cs2[len]))
	{
		len++;
		n--;
	}
	if (n)
		return (cs1[len] - cs2[len]);
	return (0);
}
