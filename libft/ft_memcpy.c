/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aionescu <aionescu@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 00:27:09 by aionescu          #+#    #+#             */
/*   Updated: 2021/06/01 19:39:43 by aionescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dest, const void *restrict src, size_t n)
{
	size_t	index;

	if (dest != NULL && src != NULL)
	{
		index = 0;
		while (index < n)
		{
			*(char *)(dest + index) = *(char *)(src + index);
			index++;
		}
	}
	return (dest);
}
