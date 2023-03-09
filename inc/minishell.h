/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda_cruz <gda_cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:37:14 by gda_cruz          #+#    #+#             */
/*   Updated: 2023/03/09 17:01:04 by gda_cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../lib/inc/libft.h"
# include "macros.h"
# include "structs.h"
# include "enums.h"
# include "ft_bool.h"

# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <linux/limits.h>
# include <limits.h>
# include <wait.h>
# include <err.h>
# include <errno.h>
# include <readline/readline.h>
# include <readline/history.h>

extern t_data	g_data;

//////////////////////////////
/********** INIT ************/
//////////////////////////////
void	init_shell(char **envp);

//////////////////////////////
/********** LEXER ***********/
//////////////////////////////

//////////////////////////////
/********** PARSER **********/
//////////////////////////////

//////////////////////////////
/********* EXECUTOR *********/
//////////////////////////////

//////////////////////////////
/********* BUILTINS *********/
//////////////////////////////

int		ft_cd(char **path);
int		ft_echo(char **str);
int		ft_env(char **data);
int		ft_export(char **new);
int		ft_pwd(char **data);
int		ft_unset(char **unset);
int		ft_exit(char **exit);

/* builtins_utils.c */
void	add_builtin(t_built **list, char *cmd, int (*f)(char **));

//////////////////////////////
/********** UTILS ***********/
//////////////////////////////

/*** env_utils.c **/
char	*get_env_value(char *value);

/**** prompt.c ****/
char	*read_input(void);

/***** utils.c ****/
int		list_has_value(char *value, t_list **list);
void	modify_value(t_list **list, char *old_value, char *new_value);

#endif