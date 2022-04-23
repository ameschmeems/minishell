/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpucylo <kpucylo@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 13:50:28 by kpucylo           #+#    #+#             */
/*   Updated: 2022/04/05 17:46:44 by kpucylo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minishell.h"

void	write_to_file(int fd, char *buff)
{
	int	i;

	i = ft_strlen(buff);
	write(fd, buff, i);
	write(fd, "\n", 1);
}

int	open_file_write(char *name, int mode)
{
	if (access(name, F_OK))
		return (open(name, O_CREAT | O_RDWR, 0666));
	else
	{
		if (mode == 1)
			return (open(name, O_WRONLY | O_TRUNC, 0666));
		else if (mode == 2)
			return (open(name, O_WRONLY | O_APPEND, 0666));
	}
	return (-1);
}

int	error(t_data *data)
{
	printf("minishell: warning: here-document delimited by \
		end-of-file (wanted '%s')\n", data->limiter);
	return (-1);
}

int	here_doc(t_data *data)
{
	int		temp_fd;
	char	*buff;

	temp_fd = open_file_write("temp_file_frog", 1);
	if (temp_fd == -1)
	{
		close(temp_fd);
		perror("here_doc");
		return (-1);
	}
	while (1)
	{
		buff = readline(">");
		if (!buff)
			return (error(data));
		if (ft_memcmp(data->limiter, buff, ft_strlen(data->limiter) + 1))
			write_to_file(temp_fd, buff);
		else
		{
			close(temp_fd);
			return (0);
		}
	}
}
