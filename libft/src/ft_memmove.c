/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcannaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:47:50 by gcannaud          #+#    #+#             */
/*   Updated: 2023/11/08 21:17:05 by gcannaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*destination;
	unsigned char	*source;

	destination = (unsigned char *)dest;
	source = (unsigned char *)src;
	if (!src && !dest)
		return (0);
	if (src > dest)
		while (n--)
			*(destination++) = *(source++);
	else
		while (n--)
			destination[n] = source[n];
	return (dest);
}
