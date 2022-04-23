/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aionescu <aionescu@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 23:16:20 by aionescu          #+#    #+#             */
/*   Updated: 2021/05/19 23:26:23 by aionescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t		index;
	const char	*ptr;

	ptr = NULL;
	index = 0;
	if (0 <= c && c <= 255)
	{
		while (s[index] != '\0')
		{
			if (s[index] == c)
			{
				ptr = s + index;
			}
			index++;
		}
		if (c == '\0')
			ptr = s + index;
	}
	return ((char *)ptr);
}
