/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   markings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpucylo <kpucylo@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:30:04 by aionescu          #+#    #+#             */
/*   Updated: 2022/04/20 21:01:37 by kpucylo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "./libft/libft.h"

void	add_marking_q(char **str)
{
	char	*marked_str;

	marked_str = ft_strjoin("\'Qwertylicious#69\'", *str);
	free(*str);
	*str = marked_str;
}

int	has_marking_q(char *str)
{
	if (ft_strncmp(str, "\'Qwertylicious#69\'", 18) == 0)
		return (1);
	else
		return (0);
}

void	remove_marking_q(char **str)
{
	char	*unmarked_str;
	int		unmarked_length;

	if (has_marking_q(*str) == 1)
	{
		unmarked_length = ft_strlen(*str + 18);
		unmarked_str = ft_calloc(unmarked_length + 1, sizeof(char));
		ft_strlcpy(unmarked_str, *str + 18, unmarked_length + 1);
		free(*str);
		*str = unmarked_str;
	}
}

char	*dup_without_marking_q(char *str)
{
	if (has_marking_q(str) == 1)
		return (ft_strdup(str + 18));
	else
		return (ft_strdup(str));
}
