/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpucylo <kpucylo@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:43:00 by kpucylo           #+#    #+#             */
/*   Updated: 2022/04/22 14:14:57 by kpucylo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minishell.h"

void	exec_all(t_data *data, int i)
{
	if (execute_built_in(data, i) == -1)
		exec_command(data->commands[i], data);
	else
		exit (0);
}

void	multi_pipe_child(int i, int *fd, int (*new_fd)[2], t_data *data)
{
	dup2(fd[0], 0);
	close(fd[0]);
	close(fd[1]);
	close(new_fd[i % 2][0]);
	dup2(new_fd[i % 2][1], 1);
	close(new_fd[i % 2][1]);
	close(new_fd[i % 2][0]);
	if (set_data(data, i, 0, 0))
		exit(1);
	exec_all(data, i);
}

void	pipe_last_command(int i, int *fd, t_data *data)
{
	pid_t	pid;
	int		wstatus;

	dup2(fd[0], 0);
	close(fd[1]);
	close(fd[0]);
	pid = fork();
	if (pid == -1)
		perror("fork error");
	g_pid = pid;
	if (!pid)
	{
		if (set_data(data, i, 0, 0))
			exit(1);
		exec_all(data, i);
	}
	waitpid(0, &wstatus, 0);
	data->exit_status = WEXITSTATUS(wstatus);
}

void	handle_pipes(int *fd, t_data *data)
{
	pid_t	pid;
	int		i;
	int		new_fd[2][2];

	i = 0;
	while (++i < data->pipes)
	{
		if (pipe(new_fd[i % 2]) == -1)
			perror("pipe error");
		pid = fork();
		if (pid == -1)
			perror("fork error");
		g_pid = pid;
		if (!pid)
			multi_pipe_child(i, fd, new_fd, data);
		else
		{
			close(fd[0]);
			close(fd[1]);
			fd = new_fd[i % 2];
		}
	}
	pipe_last_command(i, fd, data);
}

void	pipe_first_command(int *fd, t_data *data)
{
	dup2(fd[1], 1);
	close(fd[0]);
	close(fd[1]);
	if (!set_data(data, 0, 0, 0))
		exec_all(data, 0);
	else
		exit(1);
}
