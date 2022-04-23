/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aionescu <aionescu@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 15:03:08 by aionescu          #+#    #+#             */
/*   Updated: 2022/01/25 21:34:10 by aionescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	handle_beginning(const char *nptr, int *sign)
{
	int	index;

	index = 0;
	*sign = 1;
	while ((9 <= nptr[index] && nptr[index] <= 13) || nptr[index] == ' ')
		index++;
	if (nptr[index] == '+' || nptr[index] == '-')
	{
		index++;
		if (nptr[index - 1] == '-')
			*sign = -1;
	}
	return (index);
}

int	ft_atoi(const char *nptr)
{
	long	number;
	int		index;
	int		sign;

	number = 0;
	sign = 1;
	index = handle_beginning(nptr, &sign);
	while (nptr[index] != '\0')
	{
		if (nptr[index] < '0' || '9' < nptr[index])
			break ;
		number = number * 10 + (nptr[index] - '0');
		index++;
	}
	number = sign * number;
	return ((int)number);
}
