/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_function.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcannaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:29:03 by gcannaud          #+#    #+#             */
/*   Updated: 2023/12/07 23:18:28 by gcannaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_unsigned_lenint(unsigned int nb)
{
	int	j;

	j = 1;
	while (nb > 9)
	{
		nb = nb / 10;
		j++;
	}
	return (j);
}

void	ft_putunsignednbr_fd(unsigned int n, int fd)
{
	if (n > 9)
	{
		ft_putunsignednbr_fd(n / 10, fd);
		n = n % 10;
	}
	ft_putchar_fd(n + '0', fd);
}
