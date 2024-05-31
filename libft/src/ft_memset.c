/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcannaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:49:00 by gcannaud          #+#    #+#             */
/*   Updated: 2023/11/01 21:47:00 by gcannaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*cc;
	size_t			len;
	int				i;

	i = 0;
	len = 0;
	cc = s;
	while (len < n)
	{
		cc[i] = (unsigned char)c;
		i++;
		len++;
	}
	return (s);
}
