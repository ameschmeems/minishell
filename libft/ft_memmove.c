/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aionescu <aionescu@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 18:15:04 by aionescu          #+#    #+#             */
/*   Updated: 2021/05/19 22:39:11 by aionescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	index;

	index = 0;
	if (src < dest)
	{
		while (index < n)
		{
			*(char *)(dest + n - index - 1) = *(char *)(src + n - index - 1);
			index++;
		}
	}
	else
	{
		while (index < n)
		{
			*(char *)(dest + index) = *(char *)(src + index);
			index++;
		}
	}
	return (dest);
}
