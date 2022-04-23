/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aionescu <aionescu@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 23:51:43 by aionescu          #+#    #+#             */
/*   Updated: 2021/06/01 21:22:15 by aionescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current_element;

	if (lst != NULL)
	{
		while (*lst != NULL)
		{
			current_element = *lst;
			del(current_element->content);
			*lst = current_element->next;
			free(current_element);
		}
	}
}
