/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enums.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda-cruz <gda-cruz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 19:08:51 by gda_cruz          #+#    #+#             */
/*   Updated: 2023/03/07 16:09:32 by gda-cruz         ###   ########.fr       */
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

enum e_token_type
{
	WORD,
	RED,
	IO,
	PIPE,
	ENV,
	HERE,
	TERM,
	BIN
};

enum e_errors
{
	SUCCESS,
	MEMORY_ALLOCATION,
	INCORRECT_QUOTATION
};

#endif