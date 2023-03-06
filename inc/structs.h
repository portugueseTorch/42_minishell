/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda_cruz <gda_cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 13:25:07 by gda_cruz          #+#    #+#             */
/*   Updated: 2023/03/06 19:31:59 by gda_cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

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
	char	*content;
	char	*type;
}	t_cmd;

typedef struct s_data
{
	int				num_cmd;
	int				in_file;
	int				out_file;
	struct s_cmd	*cmds;
}	t_data;

#endif