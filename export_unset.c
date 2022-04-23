/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_unset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpucylo <kpucylo@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:32:14 by kpucylo           #+#    #+#             */
/*   Updated: 2022/04/17 18:47:40 by kpucylo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minishell.h"

int	validity_check(char *str)
{
	int	i;

	i = 0;
	if (!ft_isalpha(str[0]))
		i = -1;
	while (i >= 0 && str[i])
	{
		if (str[i] == '=' && str[i + 1])
			return (i);
		else if (str[i] == '=')
			return (0);
		if (!ft_isalnum(str[i]))
			break ;
		i++;
		if (i == (int)ft_strlen(str))
			return (0);
	}
	ft_putstr_fd("export: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": not a valid identifier\n", 2);
	return (0);
}

char	**append_array(char *str, char **array, int size)
{
	char	**temp;

	temp = malloc(sizeof(char *) * (size + 2));
	ft_memmove(temp, array, sizeof(char *) * size);
	temp[size] = str;
	temp[size + 1] = NULL;
	free(array);
	return (temp);
}

int	export2(char *cmd, t_data *data, int len, char *str)
{
	int	i;

	i = 0;
	while (data->envp[i])
	{
		if (!ft_strncmp(data->envp[i], cmd, len + 1))
		{
			free(data->envp[i]);
			data->envp[i] = str;
			return (0);
		}
		i++;
	}
	return (i);
}

int	export(char **cmd, t_data *data)
{
	int	retval;
	int	i;

	if (!cmd[1])
	{
		i = 0;
		while (data->envp[i])
		{
			printf("declare -x %s\n", data->envp[i]);
			i++;
		}
	}
	retval = export_loop(cmd, data);
	return (retval);
}

int	unset(char **cmd, t_data *data)
{
	int	i;
	int	len;
	int	retval;

	retval = 0;
	i = 1;
	while (cmd[i])
	{
		retval = unset_error(cmd[i]);
		if (retval)
		{
			i++;
			continue ;
		}
		len = (int)ft_strlen(cmd[i]);
		unset2(data, cmd[i], len);
		i++;
	}
	return (retval);
}
