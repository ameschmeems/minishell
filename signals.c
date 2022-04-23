/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpucylo <kpucylo@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 13:20:15 by kpucylo           #+#    #+#             */
/*   Updated: 2022/04/22 13:06:33 by kpucylo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minishell.h"

void	handle_signal(int sig)
{
	if (sig == SIGINT)
	{
		if (g_pid > 0)
		{
			kill(g_pid, SIGKILL);
			printf("\n");
		}
		else
		{
			printf("\n");
			rl_on_new_line();
			rl_replace_line("", 0);
			rl_redisplay();
		}
	}
	else if (sig == SIGQUIT)
	{
		rl_on_new_line();
	}
}

int	catch_signal(int sig, void (*handler)(int))
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, sig);
	sa.sa_handler = handler;
	sa.sa_flags = 0;
	return (sigaction(sig, &sa, NULL));
}

char	*create_new_from_temp_free(char *temp)
{
	char	*new;

	new = ft_calloc(ft_strlen(temp) + 1, sizeof(char));
	ft_strlcpy(new, temp, ft_strlen(temp) + 1);
	free(temp);
	return (new);
}
