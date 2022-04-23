/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aionescu <aionescu@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 01:50:09 by aionescu          #+#    #+#             */
/*   Updated: 2021/05/30 18:54:16 by aionescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new_str;
	unsigned int	index;

	new_str = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (new_str != NULL)
	{
		index = 0;
		while (index < ft_strlen(s))
		{
			new_str[index] = f(index, s[index]);
			index++;
		}
		new_str[index] = '\0';
	}
	return (new_str);
}
