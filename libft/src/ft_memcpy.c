/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcannaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:36:31 by gcannaud          #+#    #+#             */
/*   Updated: 2023/11/07 16:44:32 by gcannaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	len;
	char	*cdest;
	char	*csrc;
	int		i;

	i = 0;
	len = 0;
	cdest = (char *)dest;
	csrc = (char *)src;
	if (!src && !dest)
		return (0);
	while (len < n)
	{
		cdest[i] = csrc[i];
		i++;
		len++;
	}
	return (dest);
}
