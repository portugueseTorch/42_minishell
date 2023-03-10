/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enums.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda_cruz <gda_cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 19:08:51 by gda_cruz          #+#    #+#             */
/*   Updated: 2023/03/10 17:14:28 by gda_cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUMS_H
# define ENUMS_H

enum e_state
{
	IN_Q,
	IN_DQ,
	IN_CURLY,
	DEF
};

enum e_token_type
{
	DEF_CHAR	= -1,
	SPACE_CHAR	= ' ',
	USD_CHAR	= '$',
	QM_CHAR		= '?',
	PIPE_CHAR	= '|',
	AND_CHAR	= '&',
	SC_CHAR		= ';',
	QUOTE_CHAR	= '\'',
	DQUOTE_CHAR	= '\"',
	INRED_CHAR	= '<',
	OUTRED_CHAR	= '>',
	ESC_CHAR	= '\\',
	OP_CHAR		= '(',
	CP_CHAR		= ')',
	OCB_CHAR	= '{',
	CCB_CHAR	= '}',
	NULL_CHAR	= '\0',
	TOKEN		= -1
};

enum e_errors
{
	SUCCESS,
	MEMORY_ALLOCATION,
	INCORRECT_QUOTATION
};

#endif