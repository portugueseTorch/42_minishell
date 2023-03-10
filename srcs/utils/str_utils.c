/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda_cruz <gda_cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:27:44 by gda_cruz          #+#    #+#             */
/*   Updated: 2023/03/10 17:06:13 by gda_cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	is_whitespace(char c)
{
	if (c == '\t' || c == '\n' || c == '\r' || \
		c == '\v' || c == '\f' || c == ' ')
		return (1);
	return (0);
}

int	input_is_empty(char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (!is_whitespace(input[i]))
			return (0);
		i++;
	}
	return (1);
}

char	*trim_input(char *input)
{
	int	start;
	int	end;

	start = 0;
	end = ft_strlen(input);
	while (input[start] && is_whitespace(input[start]))
		start++;
	if (!input[start])
		return (ft_strdup(""));
	while (end >= 0 && is_whitespace(input[end]))
		end--;
	return (ft_substr(input, start, end - start + 1));
}

/* Checks if the current character is a terminator */
int	is_terminator(char c)
{
	if (c == INRED_CHAR || c == OUTRED_CHAR || c == SC_CHAR || \
		c == PIPE_CHAR || c == AND_CHAR || c == OP_CHAR || \
		c == CP_CHAR)
		return (1);
	return (0);
}

/* Returns the type of character c */
int	get_char_type(char c)
{
	if (c == ' ')
		return (SPACE_CHAR);
	else if (c == '$')
		return (USD_CHAR);
	else if (c == '?')
		return (QM_CHAR);
	else if (c == '|')
		return (PIPE_CHAR);
	else if (c == '&')
		return (AND_CHAR);
	else if (c == ';')
		return (SC_CHAR);
	else if (c == '\'')
		return (QUOTE_CHAR);
	else if (c == '\"')
		return (DQUOTE_CHAR);
	else if (c == '<')
		return (INRED_CHAR);
	else if (c == '>')
		return (OUTRED_CHAR);
	else if (c == '\\')
		return (ESC_CHAR);
	else if (c == '(')
		return (OP_CHAR);
	else if (c == ')')
		return (CP_CHAR);
	else if (c == '{')
		return (OCB_CHAR);
	else if (c == '}')
		return (CCB_CHAR);
	else if (c == '\0')
		return (NULL_CHAR);
	else
		return (TOKEN);
}
