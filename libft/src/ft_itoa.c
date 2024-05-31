/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcannaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 20:35:11 by gcannaud          #+#    #+#             */
/*   Updated: 2023/11/14 19:15:30 by gcannaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_printstr(int j, int i, int n, char *str)
{
	int	x;

	while (i > 0)
	{
		x = n % 10;
		n = n / 10;
		str[i - 1] = (x + '0');
		i--;
	}
	if (str[0] == '0' && str[1] > 0)
		str[0] = '-';
	str[j] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		j;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	else if (n > 0)
	{
		str = malloc(sizeof(char) * (ft_lenint(n) + 1));
		i = ft_lenint(n);
	}
	else if (n < 0)
	{
		n = n * -1;
		str = malloc(sizeof(char) * (ft_lenint(n) + 2));
		i = ft_lenint(n) + 1;
	}
	else
		return (ft_strdup("0"));
	if (!str)
		return (NULL);
	j = i;
	return (ft_printstr(j, i, n, str));
}
