/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcannaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:04:59 by gcannaud          #+#    #+#             */
/*   Updated: 2023/11/02 18:06:15 by gcannaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	n;
	size_t	len;

	n = 0;
	if (size == 0)
		return (ft_strlen(src));
	len = ft_strlen(src);
	while (n < (size - 1) && len > n)
	{
		dst[n] = src[n];
		n++;
	}
	dst[n] = 0;
	return (len);
}
