/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpucylo <kpucylo@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 14:40:29 by kpucylo           #+#    #+#             */
/*   Updated: 2022/04/17 20:15:19 by kpucylo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minishell.h"

int	echo_flag(char **cmd, int *i)
{
	int	flag;
	int	j;
	int	stop;

	flag = 0;
	stop = 0;
	if (!ft_strncmp(cmd[*i], "-n", 2) && ft_strlen(cmd[*i]) == 2)
		flag = 1;
	while (cmd[*i] && ft_strnstr(cmd[*i], "-n", 2))
	{
		j = 2;
		while (cmd[*i][j] == 'n' && !stop)
		{
			if (cmd[*i][j + 1] && cmd[*i][j + 1] != 'n')
				stop = 1;
			if (!cmd[*i][j + 1])
				flag = 1;
			j++;
		}
		if (stop)
			break ;
		(*i)++;
	}
	return (flag);
}
