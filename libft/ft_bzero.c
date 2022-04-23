/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aionescu <aionescu@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 00:19:27 by aionescu          #+#    #+#             */
/*   Updated: 2021/05/19 00:20:44 by aionescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *s, size_t n)
{
	size_t	index;
	char	*cptr;

	cptr = s;
	index = 0;
	while (index < n)
	{
		*(cptr + index) = '\0';
		index++;
	}
	return (s);
}
