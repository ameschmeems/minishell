/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aionescu <aionescu@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 19:44:17 by aionescu          #+#    #+#             */
/*   Updated: 2021/06/05 22:17:44 by aionescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nelem, size_t elsize)
{
	void		*ptr;
	char		*ptr_modifiable;
	long long	total_bytes;

	total_bytes = nelem * elsize;
	ptr_modifiable = (char *)malloc(total_bytes);
	ptr = ptr_modifiable;
	if (ptr_modifiable != NULL)
	{
		while (total_bytes > 0)
		{
			ptr_modifiable[total_bytes - 1] = 0;
			total_bytes--;
		}
	}
	return (ptr);
}
