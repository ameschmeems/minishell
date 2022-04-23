/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aionescu <aionescu@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 20:07:55 by aionescu          #+#    #+#             */
/*   Updated: 2021/06/05 15:04:29 by aionescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	const char	*position;
	size_t		s2_length;
	size_t		index;

	position = NULL;
	s2_length = ft_strlen(s2);
	index = 0;
	while (s1[index] != '\0' && index < n)
	{
		if (s1[index] == s2[0])
		{
			if (ft_strncmp(s1 + index, s2, s2_length) == 0
				&& (index + ft_strlen(s2)) <= n)
			{
				position = s1 + index;
				break ;
			}
			else
				position = NULL;
		}
		index++;
	}
	if (ft_strlen(s2) == 0)
		position = s1;
	return ((char *)position);
}
