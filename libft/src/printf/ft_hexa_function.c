/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcannaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 01:54:32 by gcannaud          #+#    #+#             */
/*   Updated: 2023/12/07 23:18:52 by gcannaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hexalonglen(unsigned long long nb)
{
	size_t	j;

	j = 1;
	while (nb > 15)
	{
		nb = nb / 16;
		j++;
	}
	return (j);
}

int	ft_hexalen(unsigned int nb)
{
	size_t	j;

	j = 1;
	while (nb > 15)
	{
		nb = nb / 16;
		j++;
	}
	return (j);
}

void	ft_puthexanbr_fd(unsigned int n, int fd, unsigned int c)
{
	if (n > 15)
	{
		ft_puthexanbr_fd(n / 16, fd, c);
		n = n % 16;
	}
	if (n <= 9)
		ft_putchar_fd(n + '0', fd);
	else
		ft_putchar_fd(n + c, fd);
}

void	ft_putargument(void *p)
{
	write (1, "0x", 2);
	ft_puthexalongnbr_fd((unsigned long long)p, 1);
}

void	ft_puthexalongnbr_fd(unsigned long long n, int fd)
{
	if (n > 15)
	{
		ft_puthexalongnbr_fd(n / 16, fd);
		n = n % 16;
	}
	if (n <= 9)
		ft_putchar_fd(n + '0', fd);
	else
		ft_putchar_fd(n + 87, fd);
}
