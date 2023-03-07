/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda-cruz <gda-cruz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:37:14 by gda_cruz          #+#    #+#             */
/*   Updated: 2023/03/07 16:52:13 by gda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../lib/inc/libft.h"
# include "macros.h"
# include "structs.h"
# include "enums.h"
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <limits.h>
# include <wait.h>
# include <err.h>
# include <errno.h>
# include <readline/readline.h>
# include <readline/history.h>

void	display_lexer(t_token **list);
void	display_cmd_table(void);

int		has_whitespace(char *str);

/********* utils.c **********/
int		is_redirect(char c);
int		is_whitespace(char c);
int		get_char_type(char c);
int		has_whitespace(char *str);
int		has_double_quotes(char *str);
int		is_variable(char *str, int i);
int		is_redirector(char *str);
int		is_builtin(char *str);

/****** list_utils.c ********/
void	add_token(t_token **list, t_token *new);
t_token	*get_last_token(t_token **list);
t_token	*new_token(char *content, int quotes);
t_token	*search_list(t_token **list, char *content);
int		list_has_content(t_token **list, char *content);
int		get_list_length(t_token **list);

int		create_pipe_token(t_token **list);
int		lexer(char *input, t_token **token);
int		create_env_token(char *input, t_token **list, int i);
int		create_redirect_token(char *input, t_token **list, int i);
int		create_quote_token(char *input, t_token **list, int i, int *status);
int		create_dquote_token(char *input, t_token **list, int i, int *status);
int		create_standard_token(char *input, t_token **list, int i, int *status);

int		parse_input(t_token **list);

#endif