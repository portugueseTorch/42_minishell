/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda_cruz <gda_cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 13:25:07 by gda_cruz          #+#    #+#             */
/*   Updated: 2023/03/03 12:21:13 by gda_cruz         ###   ########.fr       */
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

#endif