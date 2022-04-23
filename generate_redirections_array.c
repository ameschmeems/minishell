/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_redirections_array.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aionescu <aionescu@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 20:51:56 by aionescu          #+#    #+#             */
/*   Updated: 2022/04/18 20:50:18 by aionescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "./libft/libft.h"

/* Initializes the char*** with 2 NULL pointers for every string. */
char	***init_redirections_array(int nelem)
{
	char	***redirections_array;
	int		twice_nelem;

	twice_nelem = nelem * 2;
	redirections_array = malloc((twice_nelem + 1) * sizeof(char *));
	while (twice_nelem > 0)
	{
		redirections_array[twice_nelem] = NULL;
		twice_nelem--;
	}
	redirections_array[twice_nelem] = NULL;
	return (redirections_array);
}

/* Inserts two strings in the array, even if the redirection is one string */
void	insert_redirection(char **redir_arr, int nel, char **t_inp, int t_ind)
{
	int		str_index;
	char	*brackets;

	if (is_redirection(t_inp, t_ind) == 2)
	{
		remove_marking_q(&t_inp[t_ind]);
		redir_arr[nel] = ft_strdup(t_inp[t_ind]);
		remove_marking_q(&t_inp[t_ind + 1]);
		redir_arr[nel + 1] = ft_strdup(t_inp[t_ind + 1]);
	}
	else if (is_redirection(t_inp, t_ind) == 1)
	{
		remove_marking_q(&t_inp[t_ind]);
		str_index = 0;
		while (t_inp[t_ind][str_index] == '<' || t_inp[t_ind][str_index] == '>')
			str_index++;
		brackets = ft_calloc(str_index + 1, sizeof(char));
		ft_strlcpy(brackets, t_inp[t_ind], str_index + 1);
		redir_arr[nel] = brackets;
		redir_arr[nel + 1] = ft_strdup(t_inp[t_ind] + str_index);
	}
}

/* Generates an array containing all the redirections before the next pipe. */
char	**generate_redirection(char **term_input, int term_i, int nelem)
{
	char	**redirection_arr;
	int		twice_nelem;

	if (term_input[term_i] == NULL)
		return (NULL);
	twice_nelem = nelem * 2;
	redirection_arr = malloc((twice_nelem + 1) * sizeof(char *));
	while (twice_nelem > 0)
	{
		redirection_arr[twice_nelem] = NULL;
		twice_nelem--;
	}
	redirection_arr[twice_nelem] = NULL;
	while (ft_strncmp(term_input[term_i], "|\0", 2) != 0
		&& term_input[term_i] != NULL)
	{
		if (is_redirection(term_input, term_i) > 0)
		{
			insert_redirection(redirection_arr, twice_nelem, term_input, \
				term_i);
			twice_nelem = twice_nelem + 2;
		}
		term_i = term_i + 1 + (is_redirection(term_input, term_i) / 2);
	}
	return (redirection_arr);
}

/* Generates a char*** containing arrays of strings representing redirects. */
char	***generate_redirections_array(char **term_input)
{
	char	***redir_array;
	int		nelem;
	int		term_indx;
	int		arri;

	nelem = count_strings(term_input);
	if (nelem == 0)
		return (NULL);
	redir_array = init_redirections_array(nelem);
	arri = 0;
	term_indx = 0;
	while (term_input[term_indx] != NULL)
	{
		redir_array[arri] = generate_redirection(term_input, term_indx, nelem);
		while (ft_strncmp(term_input[term_indx], "|\0", 2) != 0
			&& term_input[term_indx] != NULL)
			term_indx++;
		if (ft_strncmp(term_input[term_indx], "|\0", 2) == 0)
			term_indx++;
		if (term_input[term_indx] == NULL)
			break ;
		arri++;
	}
	return (redir_array);
}
