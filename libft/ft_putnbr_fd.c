/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aionescu <aionescu@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 00:05:15 by aionescu          #+#    #+#             */
/*   Updated: 2022/01/25 21:34:47 by aionescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_generate_num_array(int n, char *num)
{
	size_t	index;
	char	sign;

	index = 10;
	sign = '+';
	if (n < 0)
		sign = '-';
	while (n != 0)
	{
		if (n < 0)
		{
			num[index] = -1 * (n % 10) + '0';
			n = n / -10;
		}
		else
		{
			num[index] = n % 10 + '0';
			n = n / 10;
		}
		index--;
	}
	if (sign == '-')
		num[index] = '-';
}

void	ft_putnbr_fd(int n, int fd)
{
	char	num[11];
	size_t	index;

	index = 0;
	while (index < 11)
	{
		num[index] = 'x';
		index++;
	}
	if (n == 0)
		num[10] = '0';
	else
		ft_generate_num_array(n, num);
	index = 0;
	while (index < 11)
	{
		if (num[index] == '-' || ('0' <= num[index] && num[index] <= '9'))
			write(fd, num + index, 1);
		index++;
	}
}
