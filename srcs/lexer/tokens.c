/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda_cruz <gda_cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:17:36 by gda_cruz          #+#    #+#             */
/*   Updated: 2023/03/03 15:23:33 by gda_cruz         ###   ########.fr       */
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
	printf("\n%s\n\n", content);
	add_token(list, new_token(content, IN_DQ));
	return (1);
}

// int	create_quote_token(char *input, t_token **list, int i)
// {
// 	;
// }

int	create_standard_token(char *input, t_token **list, int i, int *status)
{
	int		end;
	char	*content;

	if (*status == IN_DQ)
		return (create_dquote_token(input, list, i, status));
	end = i + 1;
	while (input[end])
	{
		if (get_char_type(input[end]) != CHAR)
			break ;
		end++;
	}
	content = ft_substr(input, i, end - i);
	add_token(list, new_token(content, NONE));
	return (1);
}
