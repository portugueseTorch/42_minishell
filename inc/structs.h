/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda_cruz <gda_cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 13:25:07 by gda_cruz          #+#    #+#             */
/*   Updated: 2023/03/09 16:58:58 by gda_cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "ft_bool.h"

typedef struct s_token
{
	char			*content;
	int				type;
	struct s_token	*next;
}	t_token;

typedef struct s_built
{
	char			*cmd;
	int				(*f)(char **str);
	struct s_built	*next;
}	t_built;

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