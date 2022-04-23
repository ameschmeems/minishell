/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aionescu <aionescu@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 17:15:28 by aionescu          #+#    #+#             */
/*   Updated: 2022/04/20 20:13:29 by aionescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "minishell.h"

int	ang_brackets_conditions(char *input, int index)
{
	if (((*input == ' ' || *input == '\t')
			&& (ft_strncmp(input + 1, "<<<", 3) == 0
				|| ft_strncmp(input + 1, ">>>", 3) == 0
				|| ft_strncmp(input + 1, "<>", 2) == 0
				|| ft_strncmp(input + 1, "><", 2) == 0))
		|| ((index == 0)
			&& (ft_strncmp(input, "<<<", 3) == 0
				|| ft_strncmp(input, ">>>", 3) == 0
				|| ft_strncmp(input, "<>", 2) == 0
				|| ft_strncmp(input, "><", 2) == 0)))
		return (1);
	else
		return (0);
}

int	ang_brackets_check(char *input)
{
	int	index;

	index = 0;
	while (input[index] != '\0')
	{
		if (ang_brackets_conditions(input + index, index) == 1)
		{
			if (check_all_quotes_till(input, input + index) == 0)
				return (1);
		}
		index++;
	}
	return (0);
}
