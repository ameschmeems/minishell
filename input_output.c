/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpucylo <kpucylo@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 14:58:34 by kpucylo           #+#    #+#             */
/*   Updated: 2022/04/22 13:14:53 by kpucylo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minishell.h"

int	redirect_output(t_data *data)
{
	int	fd_file_out;
	int	fd_file_err;

	if (data->srcout != 0)
	{
		fd_file_out = open_file_write(data->nameout, data->srcout);
		if (fd_file_out == -1)
			return (throw_error(data->nameout, -1));
		else
			dup_and_close(fd_file_out, 1);
	}
	if (data->srcerr != 0)
	{
		fd_file_err = open_file_write(data->namerr, data->srcerr);
		if (fd_file_err == -1)
			return (throw_error(data->namerr, -1));
		else
			dup_and_close(fd_file_err, 2);
	}
	return (0);
}

int	redirect_input(t_data *data)
{
	int	fd_file_in;

	if (data->srcin != 0)
	{
		if (!access(data->namein, F_OK))
		{
			fd_file_in = open(data->namein, O_RDONLY, 0666);
			if (fd_file_in == -1)
			{
				perror(data->namein);
				return (1);
			}
			else
			{
				dup2(fd_file_in, 0);
				close(fd_file_in);
			}
		}
		else
		{
			perror(data->namein);
			return (1);
		}
	}
	return (0);
}

int	is_err_append(char *str)
{
	if ((ft_strlen(str) == 3) && (!ft_strncmp(str, "2>>", 3)))
		return (1);
	else
		return (0);
}

int	is_both_trunc(char *str)
{
	if ((ft_strlen(str) == 2) && (!ft_strncmp(str, "&>", 2)))
		return (1);
	else
		return (0);
}

int	is_both_append(char *str)
{
	if ((ft_strlen(str) == 3) && (!ft_strncmp(str, "&>>", 3)))
		return (1);
	else
		return (0);
}
