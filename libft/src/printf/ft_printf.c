/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcannaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:09:42 by gcannaud          #+#    #+#             */
/*   Updated: 2023/12/07 23:17:30 by gcannaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_conversions(const char *s, int i, va_list ap)
{
	int	len;

	len = 0;
	if (s[i] == 'c')
		len = ft_is_character(ap);
	if (s[i] == 's')
		len = ft_is_string(ap);
	if (s[i] == 'p')
		len = ft_is_void(ap);
	if (s[i] == 'd')
		len = ft_is_integer(ap);
	if (s[i] == 'i')
		len = ft_is_integer(ap);
	if (s[i] == 'u')
		len = ft_is_unsigned_decimal(ap);
	if (s[i] == 'x')
		len = ft_is_number_hexadecimal_l(ap);
	if (s[i] == 'X')
		len = ft_is_number_hexadecimal_u(ap);
	return (len);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		c;
	int		i;

	i = 0;
	c = 0;
	if (s == NULL)
		return (-1);
	va_start(ap, s);
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1] != '%')
		{
			i++;
			c = c - 1 + ft_conversions(s, i++, ap);
		}
		else if (s[i] == '%' && s[i++ + 1] == '%')
			write(1, &s[i++], 1);
		else
			write(1, &s[i++], 1);
		c++;
	}
	va_end(ap);
	return (c);
}
