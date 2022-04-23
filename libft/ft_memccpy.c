/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aionescu <aionescu@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 16:29:13 by aionescu          #+#    #+#             */
/*   Updated: 2021/06/01 19:40:59 by aionescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	index;

	if (dest != NULL && src != NULL)
	{
		index = 0;
		while (index < n)
		{
			*(char *)(dest + index) = *(char *)(src + index);
			if (*(char *)(src + index) == c)
				return (dest + index + 1);
			index++;
		}
	}
	return (NULL);
}
