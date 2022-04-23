/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpucylo <kpucylo@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 16:16:33 by kpucylo           #+#    #+#             */
/*   Updated: 2022/04/18 15:58:12 by kpucylo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minishell.h"

int	throw_error(char *str, int code)
{
	perror(str);
	return (code);
}

//this is here for norm reasons
void	dup_and_close(int fd1, int fd2)
{
	dup2(fd1, fd2);
	close(fd1);
}

void	set_null(t_data *data)
{
	data->limiter = NULL;
	data->srcin = 0;
	data->srcout = 0;
	data->srcerr = 0;
	data->nameout = NULL;
	data->namein = NULL;
	data->namerr = NULL;
}

void	free_3d_arr(char ***arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free_arr(arr[i]);
		i++;
	}
	free(arr);
}

void	clean_exit(t_data *data, int status, int flag)
{
	close(data->orig_fds[0]);
	close(data->orig_fds[1]);
	close(data->orig_fds[2]);
	free_arr(data->envp);
	if (flag)
	{
		free_3d_arr(data->commands);
		free_3d_arr(data->redirects);
	}
	if (data->path)
		free_arr(data->path);
	exit(status);
}
