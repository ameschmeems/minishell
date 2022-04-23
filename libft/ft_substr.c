/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aionescu <aionescu@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 22:47:55 by aionescu          #+#    #+#             */
/*   Updated: 2021/06/05 18:11:45 by aionescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;

	if (s == NULL)
		return (0);
	if (start >= ft_strlen(s))
	{
		sub = (char *)malloc(sizeof(char) * 1);
		if (sub == NULL)
			return (0);
		return (sub);
	}
	else
	{
		sub = (char *)malloc(sizeof(char) * (len + 1));
		if (sub == NULL)
			return (0);
		ft_strlcpy(sub, s + start, len + 1);
	}
	return (sub);
}
