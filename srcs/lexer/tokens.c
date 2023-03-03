/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda_cruz <gda_cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:17:36 by gda_cruz          #+#    #+#             */
/*   Updated: 2023/03/03 18:28:45 by gda_cruz         ###   ########.fr       */
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
	add_token(list, new_token(content, ENV));
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
	if (*status == DEFAULT)
		*status = IN_DQ;
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
	else if (initial_status == IN_DQ && *status == DEFAULT)
	{
		if (input[i] == '\"')
			return (1);
		temp = ft_substr(input, i, end - i + 1);
		content = ft_strtrim(temp, " ");
		free(temp);
		temp = ft_strjoin("\"", content);
		free(content);
		content = ft_strdup(temp);
		free(temp);
	}
	else if (initial_status == DEFAULT && *status == IN_DQ)
	{
		temp = ft_substr(input, i, end - i + 1);
		content = ft_strtrim(temp, " ");
		free(temp);
		temp = ft_strjoin(content, "\"");
		free(content);
		content = ft_strdup(temp);
		free(temp);
	}
	add_token(list, new_token(content, IN_DQ));
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
	add_token(list, new_token(content, IN_DQ));
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
		add_token(list, new_token(content, NONE));
	else
		add_token(list, new_token(content, IN_DQ));
	return (1);
}

int	create_pipe_token(t_token **list)
{
	add_token(list, new_token(ft_strdup("|"), PIPE));
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
	add_token(list, new_token(content, REDIR));
	return (1);
}
