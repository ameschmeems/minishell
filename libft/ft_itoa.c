/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aionescu <aionescu@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 23:28:02 by aionescu          #+#    #+#             */
/*   Updated: 2022/01/25 21:34:33 by aionescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_number_length(int num)
{
	size_t		length;
	long long	llint;

	llint = num;
	length = 0;
	if (llint == 0)
		length = 1;
	if (llint < 0)
	{
		llint = llint * (-1);
		length++;
	}
	while (llint > 0)
	{
		llint = llint / 10;
		length++;
	}
	return (length);
}

char	*handle_number(char *number, long long llint, size_t index)
{
	if (llint < 0)
	{
		number[0] = '-';
		llint = llint * (-1);
	}
	while (llint > 0)
	{
		number[index] = '0' + llint % 10;
		llint = llint / 10;
		index--;
	}
	return (number);
}

char	*ft_itoa(int n)
{
	char		*number;
	size_t		number_length;
	size_t		index;
	long long	llint;

	llint = n;
	number_length = get_number_length(llint);
	number = malloc(number_length + 1);
	if (number != NULL)
	{
		number[number_length] = '\0';
		if (llint == 0)
			number[0] = '0';
		else
		{
			index = number_length - 1;
			number = handle_number(number, llint, index);
		}
	}
	return (number);
}
