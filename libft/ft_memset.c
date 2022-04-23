/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aionescu <aionescu@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 23:24:11 by aionescu          #+#    #+#             */
/*   Updated: 2021/05/19 00:15:39 by aionescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	index;
	char	*cptr;

	cptr = s;
	index = 0;
	while (index < n)
	{
		*(cptr + index) = c;
		index++;
	}
	return (s);
}
