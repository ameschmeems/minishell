/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_quoted_to_text.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aionescu <aionescu@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:19:50 by aionescu          #+#    #+#             */
/*   Updated: 2022/04/21 20:27:50 by aionescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "./libft/libft.h"

/* Returns the name of an environment variable, interpreted just like bash. */
char	*identify_env_var(char *start_ptr)
{
	char	*identified_name;
	size_t	chars;

	start_ptr++;
	if (*start_ptr == '?')
	{
		identified_name = ft_calloc(2, sizeof(char));
		identified_name[0] = '?';
		return (identified_name);
	}
	chars = 0;
	while (('A' <= start_ptr[chars] && start_ptr[chars] <= 'Z')
		|| ('a' <= start_ptr[chars] && start_ptr[chars] <= 'z'))
		chars++;
	identified_name = ft_calloc(chars + 1, sizeof(char));
	chars = 0;
	while (('A' <= start_ptr[chars] && start_ptr[chars] <= 'Z')
		|| ('a' <= start_ptr[chars] && start_ptr[chars] <= 'z'))
	{
		identified_name[chars] = start_ptr[chars];
		chars++;
	}
	return (identified_name);
}

char	*create_new_from_temp(char *temp)
{
	char	*new;

	new = ft_calloc(ft_strlen(temp) + 1, sizeof(char));
	ft_strlcpy(new, temp, ft_strlen(temp) + 1);
	return (new);
}

char	*single_quoted_to_text(char *original)
{
	char	*new;
	size_t	index;
	size_t	chars;

	chars = 0;
	index = 0;
	while (original[chars] != '\'')
		chars++;
	new = ft_calloc(chars + 1, sizeof(char));
	ft_strlcpy(new, original, chars + 1);
	return (new);
}

char	*double_quoted_to_text(char	*orig, char **envp, t_data *data)
{
	char	*new;
	char	*temp;
	char	*env_var;
	char	*temp2;
	size_t	i;

	temp = ft_calloc(1000000, 1);
	i = -1;
	while (orig[++i] != '\"')
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
	new = create_new_from_temp(temp);
	free(temp);
	return (new);
}

/* Generates a string from the quoted text containing VALUES instead of KEYS. */
/* Used on a pointer to the opening quote. */
char	*quoted_to_text(char *original, char quote, char **envp, t_data *data)
{
	char	*new;

	new = NULL;
	if (quote == '\'')
		new = single_quoted_to_text(original + 1);
	else
		new = double_quoted_to_text(original + 1, envp, data);
	return (new);
}
