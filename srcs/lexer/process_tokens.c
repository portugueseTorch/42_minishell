/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_tokens.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda_cruz <gda_cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 17:12:13 by gda_cruz          #+#    #+#             */
/*   Updated: 2023/03/13 17:08:31 by gda_cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"


static int	parse_tokens(t_suptok *suptok, t_token *curr, t_token *prev, t_lexer *lex)
{
	// int	check;

	suptok->count = 0;
	suptok->here = 0;
	suptok->semaphore = 0;
	suptok->curr = curr;
	suptok->prev = prev;
	(void) lex;
	while (suptok->curr)
	{
		if (suptok->curr->type == TOKEN)
		{
			handle_expand(suptok->curr);
			// trim_quotes();
		}
		if (suptok->prev && suptok->prev->type == INRED_CHAR && suptok->curr->type == INRED_CHAR)
			suptok->here = 1;
		else
			suptok->here = 0;
		suptok->prev = suptok->curr;
		suptok->curr = suptok->curr->next;
	}
	return (suptok->count);
}

int	process_tokens(t_lexer *lex)
{
	t_suptok	suptok;
	t_token		*curr;
	t_token		*prev;
	int			count;

	prev = NULL;
	curr = lex->token_list;
	count = parse_tokens(&suptok, curr, prev, lex);
	return (count);
}