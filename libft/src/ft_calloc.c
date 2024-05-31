/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcannaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:29:03 by gcannaud          #+#    #+#             */
/*   Updated: 2023/11/07 21:38:37 by gcannaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*ctab;
	int				i;
	size_t			len;
	unsigned char	*cc;

	i = 0;
	len = 0;
	if (!nmemb || !size)
		return (malloc(0));
	if (65535 / nmemb >= size)
	{
		if ((int)nmemb < 0 || (int)size < 0)
			return (0);
		ctab = malloc(nmemb * size);
		if (ctab == NULL)
			return (NULL);
		cc = ctab;
		while (len < (nmemb * size))
		{
			cc[i++] = 0;
			len ++;
		}
		return (ctab);
	}
	return (NULL);
}
