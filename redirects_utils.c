/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirects_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpucylo <kpucylo@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:58:34 by kpucylo           #+#    #+#             */
/*   Updated: 2022/04/17 21:13:30 by kpucylo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minishell.h"

int	is_heredoc(char *str)
{
	if ((ft_strlen(str) == 2) && (!ft_strncmp(str, "<<", 2)))
		return (1);
	else
		return (0);
}

int	is_input(char *str)
{
	if ((ft_strlen(str) == 1) && (!ft_strncmp(str, "<", 1)))
		return (1);
	else
		return (0);
}

int	is_out_trunc(char *str)
{
	if ((ft_strlen(str) == 1) && (!ft_strncmp(str, ">", 1)))
		return (1);
	else
		return (0);
}

int	is_out_append(char *str)
{
	if ((ft_strlen(str) == 2) && (!ft_strncmp(str, ">>", 2)))
		return (1);
	else
		return (0);
}

int	is_err_trunc(char *str)
{
	if ((ft_strlen(str) == 2) && (!ft_strncmp(str, "2>", 2)))
		return (1);
	else
		return (0);
}
