/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aionescu <aionescu@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 21:27:02 by aionescu          #+#    #+#             */
/*   Updated: 2021/05/30 00:48:37 by aionescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char		*new_str;
	long long	length;
	long long	index;

	new_str = NULL;
	length = 0;
	index = 0;
	while (s[length] != '\0')
	{
		length++;
	}
	new_str = malloc(length + 1 + 1);
	if (new_str != NULL)
	{
		while (index < length)
		{
			new_str[index] = s[index];
			index++;
		}
		new_str[index] = '\0';
	}
	return (new_str);
}
