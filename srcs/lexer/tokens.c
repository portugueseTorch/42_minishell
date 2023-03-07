/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda-cruz <gda-cruz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:17:36 by gda_cruz          #+#    #+#             */
/*   Updated: 2023/03/07 15:57:46 by gda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	create_env_token(char *input, t_token **list, int i)
{
	int		end;
	char	*content;

	end = i + 1;
	while (input[end])
	{
		if (get_char_type(input[end]) != CHAR)
			break ;
		end++;
	}
	content = ft_substr(input, i, end - i);
	add_token(list, new_token(content, 0));
	return (1);
}

int	create_dquote_token(char *input, t_token **list, int i, int *status)
{
	int		end;
	int		initial_status;
	char	*temp;
	char	*content;

	end = i + 1;
	initial_status = *status;
	if ((*status == IN_DQ && input[i] == '\"'))
		return (1);
	*status = IN_DQ;
	if (input[end] == '$')
		return (1);
	while (input[end])
	{
		if (input[end] == '\\' && input[end + 1] == '\"')
			end += 2;
		if (input[end] == '\"')
		{
			*status = DEFAULT;
			break ;
		}
		else if (input[end + 1] == '$')
			break ;
		end++;
	}
	if (initial_status == DEFAULT && *status == DEFAULT)
		content = ft_substr(input, i, end - i + 1);
	else
	{
		temp = ft_substr(input, i, end - i + 1);
		if (initial_status == IN_DQ && *status == DEFAULT)
			content = ft_strjoin("\"", temp);
		else if (initial_status == DEFAULT && *status == IN_DQ)
			content = ft_strjoin(temp, "\"");
		free(temp);
	}
	add_token(list, new_token(content, 1));
	return (1);
}

int	create_quote_token(char *input, t_token **list, int i, int *status)
{
	int		end;
	char	*content;

	end = i + 1;
	if (*status == DEFAULT)
		*status = IN_Q;
	while (input[end])
	{
		if (input[end] == '\\' && input[end + 1] == '\'')
			end += 2;
		if (input[end] == '\'')
		{
			*status = DEFAULT;
			break ;
		}
		end++;
	}
	content = ft_substr(input, i, end - i + 1);
	add_token(list, new_token(content, 1));
	return (1);
}

int	create_standard_token(char *input, t_token **list, int i, int *status)
{
	int		end;
	char	*content;

	if (*status == IN_DQ)
		return (create_dquote_token(input, list, i, status));
	else if (*status == IN_Q)
		return (create_quote_token(input, list, i, status));
	end = i + 1;
	if (input[i] == '\\')
		end++;
	while (input[end])
	{
		if (input[end] == '\\')
			end += 2;
		if (get_char_type(input[end]) != CHAR)
			break ;
		end++;
	}
	content = ft_substr(input, i, end - i);
	if (!has_double_quotes(content))
		add_token(list, new_token(content, 0));
	else
		add_token(list, new_token(content, 1));
	return (1);
}

int	create_pipe_token(t_token **list)
{
	add_token(list, new_token(ft_strdup("|"), 0));
	return (1);
}

int	create_redirect_token(char *input, t_token **list, int i)
{
	int		end;
	char	*content;

	end = i + 1;
	while (input[end])
	{
		if (get_char_type(input[end]) != REDIRECTS)
			break ;
		end++;
	}
	content = ft_substr(input, i, end - i);
	add_token(list, new_token(content, 0));
	return (1);
}
