/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_is.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcannaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 01:52:03 by gcannaud          #+#    #+#             */
/*   Updated: 2023/12/07 23:19:35 by gcannaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_void(va_list ap)
{
	void	*i;

	i = va_arg(ap, void *);
	if (!i)
		return (write(1, "(nil)", 5));
	ft_putargument(i);
	return (ft_hexalonglen((unsigned long long)i) + 2);
}

int	ft_is_number_hexadecimal_l(va_list ap)
{
	unsigned int	i;

	i = va_arg(ap, unsigned int);
	ft_puthexanbr_fd(i, 1, 87);
	return (ft_hexalen(i));
}

int	ft_is_number_hexadecimal_u(va_list ap)
{
	unsigned int	i;

	i = va_arg(ap, int);
	ft_puthexanbr_fd(i, 1, 55);
	return (ft_hexalen(i));
}
