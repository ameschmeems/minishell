/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aionescu <aionescu@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 23:17:13 by aionescu          #+#    #+#             */
/*   Updated: 2021/06/06 00:09:20 by aionescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first_elem;
	t_list	*new_elem;

	first_elem = NULL;
	while (lst != NULL)
	{
		new_elem = ft_lstnew(f(lst->content));
		if (new_elem == NULL)
		{
			ft_lstclear(&first_elem, del);
			return (NULL);
		}
		ft_lstadd_back(&first_elem, new_elem);
		lst = lst->next;
	}
	return (first_elem);
}
