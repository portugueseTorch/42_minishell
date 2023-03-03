/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda_cruz <gda_cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:27:44 by gda_cruz          #+#    #+#             */
/*   Updated: 2023/03/03 17:38:45 by gda_cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	is_whitespace(char c)
{
	if (c == '\t' || c == '\n' || c == '\r'
		|| c == '\v' || c == '\f' || c == ' ')
		return (1);
	return (0);
}

int	is_redirect(char c)
{
	if (c == '>' || c == '<')
		return (1);
	return (0);
}

int	has_whitespace(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (is_whitespace(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	has_double_quotes(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\"')
			return (1);
		i++;
	}
	return (0);
}

int	get_char_type(char c)
{
	if (c == '\0')
		return (EMPTY);
	else if (c == ' ')
		return (SPC);
	else if (c == '|')
		return (PIPES);
	else if (is_redirect(c))
		return (REDIRECTS);
	else if (c == '\'')
		return (QUOTE);
	else if (c == '\"')
		return (DOUBLE_QUOTE);
	else if (c == '$')
		return (DOLLAR);
	else
		return (CHAR);
}

int	is_variable(char *str, int i)
{
	while (i >= 0)
	{
		if (str[i] == ' ' || is_redirect(str[i] || str[i] == '|'))
			break ;
		if (str[i] == '$')
			return (1);
		i--;
	}
	return (0);
}
