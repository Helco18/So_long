/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcannaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 21:52:20 by gcannaud          #+#    #+#             */
/*   Updated: 2023/11/12 18:02:22 by gcannaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*resultprim;

	if (!lst || !f || !del)
		return (0);
	result = ft_lstnew(f(lst->content));
	resultprim = result;
	lst = lst->next;
	while (lst)
	{
		result->next = ft_lstnew(f(lst->content));
		if (!result->next)
		{
			ft_lstclear(&resultprim, del);
			return (NULL);
		}
		result = result->next;
		lst = lst->next;
	}
	result->next = NULL;
	return (resultprim);
}
