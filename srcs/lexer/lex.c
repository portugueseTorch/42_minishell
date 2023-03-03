/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda_cruz <gda_cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:59:37 by gda_cruz          #+#    #+#             */
/*   Updated: 2023/03/03 15:24:51 by gda_cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*	The single purpose of this file is to split the input	
	into tokens, which can later on be used by the parser
	to prepare the commands to be ran by the executor		*/

// echo $var1 "large sequence $var2 still going" $var3

int	create_token(char *input, t_token **list, int i, int *status)
{
	int	next;
	int	current_type;

	current_type = get_char_type(input[i]);
	next = get_char_type(input[i + 1]);
	if (current_type == DOLLAR && next == CHAR)
		return (create_env_token(input, list, i));
	else if (current_type == DOUBLE_QUOTE)
		return (create_dquote_token(input, list, i, status));
	// else if (current_type == QUOTE)
	// 	return (parse_quotes(QUOTE));
	// else if (next == PIPE && next != current_type)
	// 	return (create_pipe());
	// else if (is_redirect(input[i]))
	// 	return (create_redirect());
	else if (current_type == CHAR)
		return (create_standard_token(input, list, i, status));
	return (NONE);
}

static void	offset_index(int *i, char *input, t_token **list)
{
	if (input[*i] == '$')
	{
		while (input[++(*i)])
			if (get_char_type(input[*i]) != CHAR)
				break ;
	}
	else if (input[*i] == '\"')
	{
		while (input[++(*i)])
		{
			if (input[*i] == '\\' && input[(*i) + 1] == '\"')
				(*i) += 2;
			if (input[*i] == '\"')
				break ;
			else if (input[(*i) + 1] == '$')
				break ;
		}
		(*i)++;
	}
	else if (get_char_type(input[*i]) == CHAR)
	{
		if (get_last_token(list)->type == IN_DQ)
		{
			while (input[++(*i)])
			{
				if (input[*i] == '\\' && input[(*i) + 1] == '\"')
					(*i) += 2;
				if (input[*i] == '\"')
					break ;
				else if (input[(*i) + 1] == '$')
					break ;
			}
		}
		else
			while (input[++(*i)])
				if (get_char_type(input[*i]) != CHAR)
					break ;
		(*i)++;
	}
}

int	parse_input(char *input, t_token **list)
{
	int	i;
	int	check;
	int	status;

	i = 0;
	status = DEFAULT;
	while (i < (int)ft_strlen(input))
	{
		check = create_token(input, list, i, &status);
		if (check >= 0)
			offset_index(&i, input, list);
		while (input[i] == ' ')
			i++;
		// else
		// 	err_handler();
	}
	return (1);
}
