/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda_cruz <gda_cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 13:25:07 by gda_cruz          #+#    #+#             */
/*   Updated: 2023/03/10 17:32:52 by gda_cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "ft_bool.h"

/*	
	__token_struct__
	content	= string of the command
	type	= type of the token according to the e_token_type enum
	next	= next token in the list
*/
typedef struct s_token
{
	char			*content;
	int				type;
	struct s_token	*next;
}	t_token;

/*	
	__lexer_struct__
	token_list	= list of tokens to be created
	num_token	= number of tokens
*/
typedef struct s_lexer
{
	t_token	*token_list;
	int		num_token;
}	t_lexer;

typedef struct s_suplex
{
	t_token	*tokens;
	char	*input;
	int		length;
	int		state;
	int		type;
	int		i;
	int		j;
}	t_suplex;

/*	
	__Builtin_struct__
	cmd 	= command
	f 		= function to be mapped according to the command
	next	= next builtin
*/
typedef struct s_built
{
	char			*cmd;
	int				(*f)(char **str);
	struct s_built	*next;
}	t_built;

/*	
	__global_struct__
	status 		= integer exit code
	default_fd	= default file descriptors for I/O
	env			= linked list for the copy of the environment variables
	builtins	= builtin linked list
	child		= flag to signal if a process is a child process
	expanded	= flag to signal if the environment variables have been expanded
*/
typedef struct s_data
{
	int		status;
	int		default_fd[2];

	t_list	**env;
	t_built	*builtins;

	t_bool	child;
	t_bool	expanded;
}	t_data;

#endif