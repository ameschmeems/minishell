/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils_env.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpucylo <kpucylo@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 18:55:30 by aionescu          #+#    #+#             */
/*   Updated: 2022/04/17 16:14:44 by kpucylo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "minishell.h"

/* Returns the chars present AFTER the '=' sign in the KEY=VALUE pair. */
char	*get_val_of_key(char *key_value_pair)
{
	char	*value;
	size_t	index;
	size_t	useful_chars;

	index = 0;
	while (key_value_pair[index] != '=')
		index++;
	index++;
	useful_chars = ft_strlen(key_value_pair + index);
	value = ft_calloc(useful_chars + 1, sizeof(char));
	ft_strlcpy(value, key_value_pair + index, useful_chars + 1);
	return (value);
}

/* Returns the value stored in the environment variable. */
char	*get_env_var(char *var_name, char **envp, t_data *data)
{
	char	*var_value;
	size_t	index;

	if (ft_strncmp(var_name, "?", 1) == 0)
		return (ft_itoa(data->exit_status));
	var_value = NULL;
	index = 0;
	while (envp[index] != NULL)
	{
		if (ft_strncmp(envp[index], var_name, ft_strlen(var_name)) == 0
			&& ft_strnstr(envp[index], "=", ft_strlen(var_name) + 1))
		{
			var_value = get_val_of_key(envp[index]);
			break ;
		}
		index++;
	}
	if (var_value == NULL)
		var_value = ft_calloc(1, sizeof(char));
	return (var_value);
}
