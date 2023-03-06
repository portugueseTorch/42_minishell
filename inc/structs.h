/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda_cruz <gda_cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 13:25:07 by gda_cruz          #+#    #+#             */
/*   Updated: 2023/03/06 17:27:44 by gda_cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "minishell.h"

enum e_status
{
	DEFAULT,
	IN_DQ,
	IN_Q
};

enum e_token_type
{
	NONE,
	CMD,
	ARG,
	PIPE,
	REDIR,
	ENV
};

enum e_letter_type
{
	EMPTY,
	CHAR,
	SPC,
	QUOTE,
	DOUBLE_QUOTE,
	REDIRECTS,
	PIPES,
	DOLLAR
};

enum e_errors
{
	SUCCESS,
	MEMORY_ALLOCATION,
	INCORRECT_QUOTATION
};

typedef struct s_token
{
	char			*content;
	int				type;
	struct s_token	*next;
	struct s_token	*previous;
}	t_token;

typedef struct s_cmd
{
	int		i;
	int		pipe_fd[2];
	pid_t	pid;
	
}	t_cmd;

typedef struct s_data
{
	int				num_cmd;
	int				in_file;
	int				out_file;
	struct s_cmd	*commands;
}	t_data;

#endif