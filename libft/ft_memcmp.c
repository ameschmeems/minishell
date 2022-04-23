/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aionescu <aionescu@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 23:31:46 by aionescu          #+#    #+#             */
/*   Updated: 2021/06/04 15:57:49 by aionescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	int		result;

	result = 0;
	i = 0;
	if (n > 0)
	{
		while (i < n)
		{
			result = *(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i);
			if (result)
				break ;
			i++;
		}
	}
	return (result);
}
