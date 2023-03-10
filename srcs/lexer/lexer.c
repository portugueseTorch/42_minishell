/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda_cruz <gda_cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:59:37 by gda_cruz          #+#    #+#             */
/*   Updated: 2023/03/10 17:34:16 by gda_cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static int	init_suplex(t_lexer *lex, t_suplex *suplex, char *input)
{
	suplex->tokens = lex->token_list;
	suplex->input = input;
	suplex->length = ft_strlen(input);
	suplex->state = DEF;
	suplex->i = 0;
	suplex->j = 0;
	if (!init_token(suplex->tokens, ft_strlen(input)))
		return (0);
	return (1);
}

static int	init_lex(t_lexer *lex)
{
	lex->num_token = 0;
	lex->token_list = (t_token *)malloc(sizeof(t_token));
	if (!lex->token_list)
		return (0);
	return (1);
}

/*	Handle the character individually depending on its state	*/
static int	process_character(t_suplex *suplex)
{
	if (suplex->state == DEF)
		if (!handle_default(suplex))
			return (0);
	else
		handle_in_state(suplex);
}

int	lexer(char *input, t_lexer *lex)
{
	t_suplex	suplex;
	int			length;

	if (!(init_lex(lex) && !init_suplex(lex, &suplex, input)))
		return (0);
	length = ft_strlen(input);
	while (suplex.i <= length)
	{
		suplex.type = get_char_type(input[suplex.i]);
		if (!process_character(&suplex))
			return (0);
		suplex.i++;
	}
}