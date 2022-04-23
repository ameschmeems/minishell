/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirects.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpucylo <kpucylo@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:28:35 by kpucylo           #+#    #+#             */
/*   Updated: 2022/04/17 21:14:03 by kpucylo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minishell.h"

int	execute_heredoc(t_data *data, char *limiter)
{
	int	ret_val;

	data->srcin = 2;
	data->limiter = limiter;
	ret_val = here_doc(data);
	if (ret_val == -1)
		return (-1);
	data->here_doc_fd = open("temp_file_frog", O_RDONLY, 0666);
	dup2(data->here_doc_fd, 0);
	unlink("temp_file_frog");
	return (0);
}

int	execute_in(t_data *data, char *file)
{
	data->srcin = 1;
	data->namein = file;
	return (redirect_input(data));
}

int	execute_trunc(t_data *data, char *file, int fd)
{
	if (fd == OUT)
	{
		data->srcout = 1;
		data->nameout = file;
	}
	else if (fd == ERR)
	{
		data->srcerr = 1;
		data->namerr = file;
	}
	else if (fd == BOTH)
	{
		data->srcout = 1;
		data->srcerr = 1;
		data->nameout = file;
		data->namerr = file;
	}
	return (redirect_output(data));
}

int	execute_append(t_data *data, char *file, int fd)
{
	if (fd == OUT)
	{
		data->nameout = file;
		data->srcout = 2;
	}
	else if (fd == ERR)
	{
		data->namerr = file;
		data->srcerr = 2;
	}
	else if (fd == BOTH)
	{
		data->nameout = file;
		data->namerr = file;
		data->srcout = 2;
		data->srcerr = 2;
	}
	return (redirect_output(data));
}
