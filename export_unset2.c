/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_unset2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpucylo <kpucylo@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 18:21:55 by kpucylo           #+#    #+#             */
/*   Updated: 2022/04/22 13:22:27 by kpucylo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minishell.h"

int	unset_error(char *str)
{
	int	i;

	i = 0;
	if (!ft_isalpha(str[0]))
		i = -1;
	while (i >= 0 && str[i])
	{
		if (!ft_isalnum(str[i]))
			break ;
		i++;
		if (i == (int)ft_strlen(str))
			return (0);
	}
	ft_putstr_fd("unset: ", 2);
	ft_putstr_fd("str", 2);
	ft_putstr_fd(": not a valid identifier\n", 2);
	return (1);
}

void	unset2(t_data *data, char *str, int len)
{
	int	i;

	i = 0;
	while (data->envp[i])
	{
		if (!ft_strncmp(data->envp[i], str, len))
		{
			free(data->envp[i]);
			while (data->envp[i + 1])
			{
				data->envp[i] = data->envp[i + 1];
				i++;
			}
			data ->envp[i] = data->envp[i + 1];
			break ;
		}
		i++;
	}
}
