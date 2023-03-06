/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enums.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda_cruz <gda_cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 19:08:51 by gda_cruz          #+#    #+#             */
/*   Updated: 2023/03/06 19:10:02 by gda_cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUMS_H
# define ENUMS_H

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

#endif