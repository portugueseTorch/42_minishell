/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda_cruz <gda_cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:37:14 by gda_cruz          #+#    #+#             */
/*   Updated: 2023/03/03 12:23:35 by gda_cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../lib/inc/libft.h"
# include "lexer.h"
# include "utils.h"
# include "structs.h"
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

typedef struct s_token
{
	char			*content;
	int				type;
	struct s_token	*next;
	struct s_token	*previous;
}	t_token;

enum e_errors
{
	SUCCESS,
	MEMORY_ALLOCATION,
	INCORRECT_QUOTATION
};

int		has_whitespace(char *str);

/********* utils.c **********/
int		is_redirect(char c);
int		is_whitespace(char c);
int		get_char_type(char c);
int		has_whitespace(char *str);
int		is_variable(char *str, int i);

/****** list_utils.c ********/
void	add_token(t_token **list, t_token *new);
t_token	*get_last_token(t_token **list);
t_token	*new_token(char *content, int type);

int		parse_input(char *input, t_token **token);
int		create_env_token(char *input, t_token **list, int i);
int		create_dquote_token(char *input, t_token **list, int i, int *status);
int		create_standard_token(char *input, t_token **list, int i, int *status);

#endif