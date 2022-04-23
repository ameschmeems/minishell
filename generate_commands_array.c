/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_commands_array.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aionescu <aionescu@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 20:12:20 by aionescu          #+#    #+#             */
/*   Updated: 2022/04/18 18:07:43 by aionescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "./libft/libft.h"

/* Initializes the char*** with as many NULL pointers as there are strings. */
char	***init_commands_array(int nelem)
{
	char	***commands_array;

	commands_array = malloc((nelem + 1) * sizeof(char *));
	while (nelem > 0)
	{
		commands_array[nelem] = NULL;
		nelem--;
	}
	commands_array[nelem] = NULL;
	return (commands_array);
}

/* Initializes the char** with as many NULL pointers as there are strings. */
char	**init_command(int nel)
{
	char	**command_array;

	command_array = malloc((nel + 1) * sizeof(char *));
	while (nel > 0)
	{
		command_array[nel] = NULL;
		nel--;
	}
	command_array[nel] = NULL;
	return (command_array);
}

/* Generates a char** containing the strings of a command and its args/flags. */
char	**generate_command(char **t_input, int t_index, int nel)
{
	char	**command_array;

	if (t_input[t_index] == NULL)
		return (NULL);
	command_array = init_command(nel);
	nel = 0;
	while (t_input[t_index] != NULL
		&& ft_strncmp(t_input[t_index], "|\0", 2) != 0)
	{
		t_index = t_index + check_for_redirections(t_input, t_index);
		if (t_input[t_index] != NULL
			&& ft_strncmp(t_input[t_index], "|\0", 2) != 0)
		{
			command_array[nel] = dup_without_marking_q(t_input[t_index]);
			nel++;
			t_index++;
		}
	}
	if (nel == 0)
	{
		free(command_array);
		return (NULL);
	}
	return (command_array);
}

/* Generates a char*** containing arrays of strings representing commands. */
char	***generate_commands_array(char **term_input)
{
	char	***commands_array;
	int		nelem;
	int		term_indx;
	int		arri;

	nelem = count_strings(term_input);
	if (nelem == 0)
		return (NULL);
	commands_array = init_commands_array(nelem);
	arri = 0;
	term_indx = 0;
	while (term_input[term_indx] != NULL)
	{
		commands_array[arri] = generate_command(term_input, term_indx, nelem);
		if (commands_array[arri] == NULL)
			break ;
		while (term_input[term_indx] != NULL
			&& ft_strncmp(term_input[term_indx], "|\0", 2) != 0)
			term_indx++;
		if (term_input[term_indx] != NULL)
			term_indx++;
		arri++;
	}
	return (commands_array);
}
