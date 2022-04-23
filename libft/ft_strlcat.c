/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aionescu <aionescu@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 19:48:21 by aionescu          #+#    #+#             */
/*   Updated: 2021/06/05 19:12:41 by aionescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	index;
	size_t	start;
	size_t	result;

	start = ft_strlen(dest);
	index = 0;
	if (ft_strlen(dest) < size)
	{
		result = ft_strlen(dest) + ft_strlen(src);
		while (((start + index) < (size - 1)) && (src[index] != '\0'))
		{
			dest[start + index] = src[index];
			index++;
		}
		dest[start + index] = '\0';
	}
	else
		result = ft_strlen(src) + size;
	return (result);
}
