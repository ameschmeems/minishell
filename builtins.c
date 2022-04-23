/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpucylo <kpucylo@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 13:37:43 by kpucylo           #+#    #+#             */
/*   Updated: 2022/04/22 13:21:36 by kpucylo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minishell.h"

int	echo(char **cmd)
{
	int	i;
	int	flag;

	i = 1;
	flag = 0;
	flag = echo_flag(cmd, &i);
	while (cmd[i])
	{
		ft_putstr_fd(cmd[i], 1);
		if (cmd[i + 1])
			ft_putstr_fd(" ", 1);
		i++;
	}
	if (!flag)
		ft_putstr_fd("\n", 1);
	return (0);
}

int	cd(char **cmd, t_data *data)
{
	int		error;
	char	*chdirpath;

	chdirpath = get_env_var("HOME", data->envp, data);
	if (!cmd[1])
		error = chdir(chdirpath);
	else
		error = chdir(cmd[1]);
	free(chdirpath);
	if (error == -1)
	{
		perror("cd");
		return (1);
	}
	return (0);
}

int	pwd(char **cmd)
{
	char	*cwd;

	if (cmd[1] && cmd[1][0] == '-')
	{
		ft_putstr_fd("pwd: ", 2);
		ft_putstr_fd(cmd[1], 2);
		ft_putstr_fd(": invalid option\n", 2);
		return (1);
	}
	cwd = NULL;
	cwd = getcwd(cwd, 0);
	printf("%s\n", cwd);
	free(cwd);
	return (0);
}

int	env(char **cmd, t_data *data)
{
	int	i;

	if (cmd[1])
	{
		ft_putstr_fd("env: ", 2);
		ft_putstr_fd(cmd[1], 2);
		ft_putstr_fd(": invalid option", 2);
		return (1);
	}
	i = 0;
	while (data->envp[i])
	{
		printf("%s\n", data->envp[i]);
		i++;
	}
	return (0);
}

int	ft_exit(char **cmd, t_data *data)
{
	int	status;
	int	i;

	i = 0;
	if (cmd[1])
	{
		if (cmd[2])
		{
			ft_putstr_fd("exit: too many arguments\n", 2);
			return (1);
		}
		while (cmd[1][i])
		{
			if (ft_isdigit(cmd[1][i]))
				i++;
			else
				clean_exit(data, 255, 1);
		}
		status = ft_atoi(cmd[1]);
		clean_exit(data, status, 1);
	}
	clean_exit(data, 0, 1);
	return (0);
}
