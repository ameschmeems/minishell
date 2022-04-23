/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils_strings.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpucylo <kpucylo@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 19:14:08 by aionescu          #+#    #+#             */
/*   Updated: 2022/04/20 21:47:22 by kpucylo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "minishell.h"

char	*ft_strjoin_three(char *first, char *second, char *third)
{
	char	*final_str;
	size_t	str_len;
	size_t	index;

	str_len = 0;
	str_len = str_len + ft_strlen(first);
	str_len = str_len + ft_strlen(second);
	str_len = str_len + ft_strlen(third);
	str_len = str_len + 10;
	final_str = ft_calloc(str_len + 1, sizeof(char));
	index = 0;
	ft_strlcpy(final_str, first, ft_strlen(first) + 1);
	ft_strlcat(final_str, second, ft_strlen(first) + ft_strlen(second) + 1);
	ft_strlcat(final_str, third, str_len + 1);
	return (final_str);
}

void	merge_chars_and_env_val(char *merged, char *start_ptr, char *env_val)
{
	int		index;

	index = 0;
	while (start_ptr[index] != '\0' && start_ptr[index] != ' '
		&& start_ptr[index] != '\t')
	{
		if (start_ptr[index] == '$')
		{
			ft_strlcat(merged, env_val, index + ft_strlen(env_val) + 1);
			break ;
		}
		merged[index] = start_ptr[index];
		index++;
	}
	free(env_val);
}

/* Reads until '\0' or ' ' or '\t' and creates and returns a string from it. */
char	*word_to_string(char *orig, char **envp, t_data *data)
{
	char	*new;
	char	*temp;
	char	*env_var;
	char	*temp2;
	size_t	i;

	temp = ft_calloc(1000000, 1);
	i = -1;
	while (orig[++i] != ' ' && orig[i] != '\t' && orig[i] != '\0'
		&& orig[i] != '\'' && orig[i] != '\"')
	{
		if (orig[i] != '$')
			ft_strlcat(temp, orig + i, ft_strlen(temp) + 2);
		else
		{
			env_var = identify_env_var(orig + i);
			temp2 = get_env_var(env_var, envp, data);
			i = i + ft_strlen(env_var);
			ft_strlcat(temp, temp2, 1000000);
			free(env_var);
			free(temp2);
		}
	}
	new = create_new_from_temp_free(temp);
	return (new);
}

/* Returns the number of strings in an array of strings. */
int	count_strings(char **terminal_input)
{
	int	count;

	count = 0;
	if (terminal_input != NULL)
	{
		while (terminal_input[count] != NULL)
		count++;
	}
	return (count);
}
