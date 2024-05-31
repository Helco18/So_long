/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcannaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:31:40 by gcannaud          #+#    #+#             */
/*   Updated: 2023/12/07 23:19:17 by gcannaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_character(va_list ap)
{
	int	c;

	c = va_arg(ap, int);
	write (1, &c, 1);
	return (1);
}

int	ft_is_string(va_list ap)
{
	int		i;
	char	*s;

	s = va_arg(ap, char *);
	i = 0;
	if (!s)
		return (write(1, "(null)", 6));
	if (s)
	{
		while (s[i])
		{
			write(1, &s[i], 1);
			i++;
		}
	}
	return (ft_strlen(s));
}

int	ft_is_integer(va_list ap)
{
	int	i;

	i = va_arg(ap, int);
	ft_putnbr_fd(i, 1);
	return (ft_lenint(i));
}

int	ft_is_unsigned_decimal(va_list ap)
{
	unsigned int	i;

	i = va_arg(ap, unsigned int);
	ft_putunsignednbr_fd(i, 1);
	return (ft_unsigned_lenint(i));
}
