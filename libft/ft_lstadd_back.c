/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aionescu <aionescu@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 21:25:03 by aionescu          #+#    #+#             */
/*   Updated: 2021/06/05 22:47:04 by aionescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (lst != NULL)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			temp = ft_lstlast(*lst);
			temp->next = new;
			new->next = NULL;
		}
	}
}
