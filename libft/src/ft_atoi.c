/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcannaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 17:48:54 by gcannaud          #+#    #+#             */
/*   Updated: 2023/11/02 14:14:46 by gcannaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	variable(int *i, int *r, int *nb)
{
	*i = 0;
	*r = 0;
	*nb = 0;
}

int	ft_atoi(const char *str)
{
	int	i;
	int	r;
	int	nb;

	variable(&i, &r, &nb);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i + 1] == ' ' || (str[i + 1] >= 9 && str[i + 1] <= 13))
			return (0);
		if (str[i] == '-')
			nb++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + str[i] - '0';
		i++;
	}
	if (nb % 2)
		return (-r);
	return (r);
}
