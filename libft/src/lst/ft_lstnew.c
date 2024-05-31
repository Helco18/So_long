/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcannaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:52:17 by gcannaud          #+#    #+#             */
/*   Updated: 2023/11/12 18:02:03 by gcannaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*p;

	p = 0;
	p = malloc(sizeof(t_list) * 1);
	if (p == NULL)
		return (NULL);
	p->content = content;
	p->next = NULL;
	return (p);
}
