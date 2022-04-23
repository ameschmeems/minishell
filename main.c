/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpucylo <kpucylo@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:50:25 by kpucylo           #+#    #+#             */
/*   Updated: 2022/04/22 14:24:16 by kpucylo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minishell.h"

char	*get_prompt(void)
{
	char	*cwd;
	char	*temp;
	char	*prompt;
	char	**temp_arr;
	int		i;

	cwd = NULL;
	cwd = getcwd(cwd, 0);
	temp_arr = ft_split(cwd, '/');
	free(cwd);
	i = 0;
	while (temp_arr[i])
		i++;
	if (!temp_arr[0])
		temp = ft_strjoin("minishell ", "/");
	else
		temp = ft_strjoin("minishell ", temp_arr[i - 1]);
	prompt = ft_strjoin(temp, " $ ");
	free(temp);
	free_arr(temp_arr);
	return (prompt);
}

char	**copy_array(char **array)
{
	char	**retval;
	int		i;

	i = 0;
	while (array[i])
		i++;
	retval = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (array[i])
	{
		retval[i] = ft_strdup(array[i]);
		i++;
	}
	retval[i] = 0;
	return (retval);
}

void	get_input(char **line)
{
	char	*prompt;

	prompt = get_prompt();
	line[0] = readline((const char *) prompt);
	free(prompt);
}

void	cleanup(char *line, t_data *data)
{
	dup2(data->orig_fds[0], 0);
	dup2(data->orig_fds[1], 1);
	dup2(data->orig_fds[2], 2);
	close(data->orig_fds[0]);
	close(data->orig_fds[1]);
	close(data->orig_fds[2]);
	free(line);
	g_pid = 0;
	if (data->path)
		free_arr(data->path);
	if (data->commands)
		free_3d_arr(data->commands);
	if (data->redirects)
		free_3d_arr(data->redirects);
	init(data, data->envp, 1);
	if (!access("temp_file_frog", F_OK))
		unlink("temp_file_frog");
}

pid_t	g_pid = 0;

int	main(int argc, char **argv, char **envp)
{
	t_data	*data;
	char	*line;

	if (argc != 1 || argv[0] == 0)
		exit(1);
	data = malloc(sizeof(t_data));
	init(data, envp, 0);
	while (1)
	{
		get_input(&line);
		if (!line)
			clean_exit(data, 0, 0);
		add_history(line);
		if (check_all_quotes(line) || ang_brackets_check(line))
			ft_putstr_fd("Error: invalid input.\n", 2);
		else if (*line && check_all_quotes(line) == 0)
		{
			parse(line, data);
			execute_line(data);
			while (wait(0) != -1)
				continue ;
		}
		cleanup(line, data);
	}
}
