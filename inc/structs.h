/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda-cruz <gda-cruz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 13:25:07 by gda_cruz          #+#    #+#             */
/*   Updated: 2023/03/07 16:53:22 by gda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_token
{
	int				quotes;
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
	char	**command;
	char	*type;
}	t_cmd;

typedef struct s_data
{
	// Executor info
	char			*in_file;
	char			*out_file;
	int				num_cmd;
	struct s_cmd	**cmds;
	// Random Info
	int				exit_status;
}	t_data;

#endif