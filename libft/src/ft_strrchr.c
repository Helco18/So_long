/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcannaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:29:26 by gcannaud          #+#    #+#             */
/*   Updated: 2023/11/07 16:48:52 by gcannaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = -1;
	while (s[i])
	{
		if (s[i] == (unsigned char) c)
			tmp = i;
		i++;
	}
	if (tmp >= 0)
		return ((char *) &s[tmp]);
	if (s[i] == (unsigned char) c)
		return ((char *) &s[i]);
	return (NULL);
}
