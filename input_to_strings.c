/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_to_strings.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aionescu <aionescu@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 18:56:37 by aionescu          #+#    #+#             */
/*   Updated: 2022/04/22 19:19:44 by aionescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "minishell.h"

/* Determines whether the "word" pointed to by *start_ptr has a quote. */
int	has_quote(char *start_ptr)
{
	int	quotes;
	int	index;

	index = 0;
	quotes = 0;
	while (start_ptr[index] != '\0')
	{
		if (start_ptr[index] == '\'' || start_ptr[index] == '\"')
			quotes++;
		if (start_ptr[index] == ' ' || start_ptr[index] == '\t')
		{
			if (quotes == 0)
				return (0);
			else
				return (1);
		}
		index++;
	}
	if (quotes == 0)
		return (0);
	else
		return (1);
}

/* Returns the length of the "word" pointed to by *start_ptr. */
int	final_string_length(char *start_ptr)
{
	int		index;

	index = 0;
	while (start_ptr[index] != '\0')
	{
		if ((start_ptr[index] == ' ' || start_ptr[index] == '\t')
			&& index_is_quoted(start_ptr, index) == 0)
		{
			break ;
		}
		index++;
	}
	return (index);
}

/* Returns the number of strings needed for the final array of strings. */
int	count_needed_strings(char *input)
{
	int		count;
	size_t	index;

	count = 0;
	index = 0;
	while (input[index] != '\0')
	{
		if (input[index] == ' ' || input[index] == '\t')
			index++;
		else
		{
			count++;
			index = index + final_string_length(input + index);
		}
	}
	return (count);
}

/* Generates and returns the next string for the array of strings. */
char	*parse_word(char *start_ptr, t_data *data)
{
	char	*new_str;
	int		index;
	char	*temp;

	index = 0;
	temp = ft_calloc(1000000, sizeof(char));
	while (start_ptr[index] != ' ' && start_ptr[index] != '\t'
		&& start_ptr[index] != '\0')
	{
		if (start_ptr[index] == '\'')
			index = index + handle_single_q(start_ptr + index, temp);
		else if (start_ptr[index] == '\"')
			index = index + handle_double_q(start_ptr + index, temp, data);
		else if (start_ptr[index] == '$')
			index = index + handle_env_var(start_ptr + index, temp, data);
		else
			ft_strlcat(temp, start_ptr + index, ft_strlen(temp) + 1 + 1);
		index++;
	}
	new_str = ft_strdup(temp);
	free(temp);
	return (new_str);
}

/* Generates an array of strings based on the terminal input. */
char	**input_to_strings(char *input, t_data *data)
{
	char	**array_of_strs;
	size_t	index;
	int		count;

	count = count_needed_strings(input);
	array_of_strs = ft_calloc((count + 1), sizeof(char *));
	count = 0;
	index = 0;
	while (input[index] != '\0')
	{
		if (input[index] == ' ' || input[index] == '\t')
			index++;
		else
		{
			array_of_strs[count] = parse_word(input + index, data);
			if (has_quote(input + index)
				&& has_clean_brackets(input + index) == 0)
				add_marking_q(&(array_of_strs[count]));
			count++;
			index = index + final_string_length(input + index);
		}
	}
	array_of_strs[count] = NULL;
	return (array_of_strs);
}
