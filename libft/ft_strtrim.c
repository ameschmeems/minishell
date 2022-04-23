/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aionescu <aionescu@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 23:20:06 by aionescu          #+#    #+#             */
/*   Updated: 2022/01/25 21:35:08 by aionescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_removable_mem(char const *s1, char const *set)
{
	size_t	removable;
	size_t	index;

	removable = 0;
	index = 0;
	while (ft_strchr(set, s1[index]) != NULL)
	{
		removable++;
		index++;
	}
	index = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[index]) != NULL)
	{
		removable++;
		index--;
	}
	return (removable);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str_trimmed;
	int		needed_mem;
	size_t	index;

	if (s1 != NULL && set != NULL)
	{
		needed_mem = (ft_strlen(s1) - get_removable_mem(s1, set) + 1);
		str_trimmed = malloc(sizeof(char) * needed_mem);
		if (needed_mem < 0)
		{
			str_trimmed = (char *)malloc(1);
			str_trimmed[0] = '\0';
		}
		else if (str_trimmed != NULL)
		{
			index = 0;
			while (ft_strchr(set, s1[index]) != NULL)
				index++;
			ft_strlcpy(str_trimmed, (s1 + index), needed_mem);
		}
	}
	else
		str_trimmed = NULL;
	return (str_trimmed);
}
