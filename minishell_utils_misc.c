/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils_misc.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpucylo <kpucylo@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 19:49:47 by aionescu          #+#    #+#             */
/*   Updated: 2022/04/22 14:27:13 by kpucylo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "./libft/libft.h"

int	count_pipes(char **terminal_array)
{
	int	pipes;
	int	index;

	pipes = 0;
	index = 0;
	while (terminal_array[index] != NULL)
	{
		if (ft_strncmp(terminal_array[index], "|\0", 2) == 0)
			pipes++;
		index++;
	}
	return (pipes);
}

void	parse(char *str, t_data *data)
{
	char	**temp;

	temp = input_to_strings(str, data);
	data->commands = generate_commands_array(temp);
	data->redirects = generate_redirections_array(temp);
	data->pipes = count_pipes(temp);
	free_arr(temp);
}

//fck the norm
int	export_loop(char **cmd, t_data *data)
{
	int		i;
	char	*str;
	int		len;
	int		retval;
	int		size;

	i = 0;
	retval = 0;
	while (cmd[++i])
	{
		len = validity_check(cmd[i]);
		if (!len)
		{
			retval = 1;
			continue ;
		}
		str = ft_strdup(cmd[i]);
		size = export2(cmd[i], data, len, str);
		if (size)
			data->envp = append_array(str, data->envp, size);
		retval = 0;
	}
	return (retval);
}
