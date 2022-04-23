/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_quoted.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aionescu <aionescu@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 19:23:38 by aionescu          #+#    #+#             */
/*   Updated: 2022/04/21 22:58:08 by aionescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "minishell.h"

/* Creates a string containing only the characters before a quoted part. */
char	*createstr_beforequote(char *start_ptr, char **envp, t_data *data)
{
	char	*beforequote;
	char	quote;
	size_t	index;

	index = 0;
	quote = what_is_next_quote(start_ptr);
	while (start_ptr[index] != quote)
		index++;
	beforequote = word_to_string(start_ptr, envp, data);
	return (beforequote);
}

/* Returns a pointer to the first adjacent character after a quoted part. */
char	*find_afterquote(char *start_ptr)
{
	char	*afterquote_ptr;
	char	quote;
	int		quote_no;
	size_t	index;

	index = 0;
	quote = what_is_next_quote(start_ptr);
	quote_no = 0;
	while (start_ptr[index] != '\0' && quote_no < 2)
	{
		if (start_ptr[index] == quote)
			quote_no++;
		index++;
	}
	afterquote_ptr = &(start_ptr[index]);
	return (afterquote_ptr);
}

/* Creates a string containing only the characters after a quoted part. */
char	*createstr_afterquote(char *start_ptr, char **envp, t_data *data)
{
	char	*afterquote_str;
	char	*afterquote_ptr;
	char	*ptr;
	size_t	index;
	size_t	sec_index;

	afterquote_ptr = find_afterquote(start_ptr);
	index = 0;
	while (afterquote_ptr[index] != ' ' && afterquote_ptr[index] != '\0'
		&& afterquote_ptr[index] != '\t' && afterquote_ptr[index] != '\''
		&& afterquote_ptr[index] != '\"')
		index++;
	sec_index = index;
	while (afterquote_ptr[sec_index] != ' ' && afterquote_ptr[sec_index] != '\0'
		&& afterquote_ptr[sec_index] != '\t')
		sec_index++;
	afterquote_str = word_to_string(afterquote_ptr, envp, data);
	ptr = ft_calloc(ft_strlen(afterquote_str) + \
		ft_strlen(afterquote_ptr) + 1, 1);
	ft_memcpy(ptr, afterquote_str, ft_strlen(afterquote_str));
	ft_memmove(ptr + ft_strlen(ptr), afterquote_ptr + index, sec_index - index);
	free(afterquote_str);
	return (ptr);
}

/* Creates one string containing a quoted part and its adjacent characters. */
/* !!! Input string has to be verified for adjacency BEFOREHAND !!! */
char	*join_quoted(char *start_ptr, char quote, char **envp, t_data *data)
{
	char	*beforequote_ptr;
	char	*quoted_ptr;
	char	*afterquote_ptr;
	char	*joined;
	size_t	index;

	index = 0;
	while (start_ptr[index] != quote)
		index++;
	beforequote_ptr = createstr_beforequote(start_ptr, envp, data);
	quoted_ptr = quoted_to_text(&(start_ptr[index]), quote, envp, data);
	afterquote_ptr = createstr_afterquote(start_ptr, envp, data);
	joined = ft_strjoin_three(beforequote_ptr, quoted_ptr, afterquote_ptr);
	free(beforequote_ptr);
	free(quoted_ptr);
	free(afterquote_ptr);
	return (joined);
}
