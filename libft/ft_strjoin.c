/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aionescu <aionescu@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 21:52:52 by aionescu          #+#    #+#             */
/*   Updated: 2021/06/06 13:47:58 by aionescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str_new;
	size_t	len_s1;
	size_t	len_s2;

	if (s1 != NULL && s2 != NULL)
	{
		len_s1 = ft_strlen(s1);
		len_s2 = ft_strlen(s2);
		str_new = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
		if (str_new != NULL)
		{
			ft_strlcpy(str_new, s1, len_s1 + 1);
			ft_strlcat(str_new, s2, len_s1 + len_s2 + 1);
		}
	}
	else
		str_new = NULL;
	return (str_new);
}
