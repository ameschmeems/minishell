/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aionescu <aionescu@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 22:50:45 by aionescu          #+#    #+#             */
/*   Updated: 2021/05/30 14:51:04 by aionescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			index;

	ptr = NULL;
	index = 0;
	{
		while (index < n)
		{
			if (*(unsigned char *)(s + index) == (unsigned char)c)
			{
				ptr = (unsigned char *)(s + index);
				break ;
			}
			index++;
		}
	}
	return ((void *)ptr);
}
