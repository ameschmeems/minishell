/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aionescu <aionescu@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 18:58:49 by aionescu          #+#    #+#             */
/*   Updated: 2022/04/22 19:13:21 by aionescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "minishell.h"

/* - Identifies and expands an environment variable */
/* - Appends the expanded value to the string *temp */
/* - Returns the number of chars to skip in the original string. */
int	handle_env_var(char *start, char *temp, t_data *data)
{
	char	*var_name;
	char	*var_value;
	char	skippable_chars;

	var_name = identify_env_var(start);
	skippable_chars = ft_strlen(var_name);
	var_value = get_env_var(var_name, data->envp, data);
	ft_strlcat(temp, var_value, ft_strlen(temp) + ft_strlen(var_value) + 1);
	free(var_name);
	free(var_value);
	return (skippable_chars);
}

/* - Appends the read characters to the string *temp */
/* - Returns the number of chars to skip in the original string. */
int	handle_single_q(char *start, char *temp)
{
	int	index;

	index = 0;
	index++;
	while (start[index] != '\'')
	{
		ft_strlcat(temp, start + index, ft_strlen(temp) + 1 + 1);
		index++;
	}
	return (index);
}

/* - Appends the read characters to the string *temp */
/* - Identifies and expands an environment variable */
/* - Appends the expanded value to the string *temp */
/* - Returns the number of chars to skip in the original string. */
int	handle_double_q(char *start, char *temp, t_data *data)
{
	int	index;

	index = 0;
	index++;
	while (start[index] != '\"')
	{
		if (start[index] == '$')
			index = index + handle_env_var(start + index, temp, data);
		else
			ft_strlcat(temp, start + index, ft_strlen(temp) + 1 + 1);
		index++;
	}
	return (index);
}
