/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda_cruz <gda_cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:59:37 by gda_cruz          #+#    #+#             */
/*   Updated: 2023/03/13 18:16:18 by gda_cruz         ###   ########.fr       */
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
	// printf("%s, %d, %d, %d, %d\n", suplex->input, suplex->length, suplex->state, suplex->i, suplex->j);
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
	{
		if (!handle_default(suplex))
			return (0);
	}
	else
		handle_in_state(suplex);
	if ( suplex->type == NULL_CHAR)
	{
		if (suplex->j > 0)
			suplex->j = 0;
	}
	return (1);
}

static void	display_info(t_lexer *lex)
{
	t_lexer	*temp;

	temp = lex;
	printf(" ------------------------------- \n");
	printf("|          Lexer Info           |\n");
	printf(" ------------------------------- \n");

	for (; temp->token_list; temp->token_list = temp->token_list->next)
	{
		printf("Content: %s\nType: %d\n", temp->token_list->content, temp->token_list->type);
		printf(" ------------------------------- \n");
	}

// 	printf(" ------------------------------- \n");
// 	printf("|          Suple Info           |\n");
// 	printf(" ------------------------------- \n");
// 	printf("Type: %d\nState: %d\nI: %d\nJ: %d\n", sup->type, sup->state, sup->i, sup->j);
// 	printf(" ------------------------------- \n\n");
}

int	correctly_quoted(char *input)
{
	int	state;
	int	i;
	int	count;

	state = DEF;
	i = -1;
	count = 0;
	while (input[++i])
	{
		if (state == DEF)
		{
			if (input[i] == '\\')
				i++;
			else if (input[i] == '\'' || input[i] == '\"')
			{
				if (input[i] == '\'')
					state = IN_Q;
				else if (input[i] == '\"')
					state = IN_DQ;
				count++;
			}
		}
		else if (state == IN_DQ)
		{
			if (input[i] == '\\')
				i++;
			else if (input[i] == '\"')
			{
				state = DEF;
				count++;
			}
		}
		else if (state == IN_Q)
		{
			if (input[i] == '\'')
			{
				state = DEF;
				count++;
			}
		}
	}
	return ((count % 2) == 0);
}

int	lexer(char *input, t_lexer *lex)
{
	t_suplex	suplex;
	int			length;
	int			num_tokens;

	if (!correctly_quoted(input))
		return (0);
	if (!init_lex(lex))
		return (0);
	if (!init_suplex(lex, &suplex, input))
		return (0);
	length = ft_strlen(input);
	while (suplex.i <= length)
	{
		suplex.type = get_char_type(input[suplex.i]);
		// printf("HI\n");
		if (!process_character(&suplex))
			return (0);
		suplex.i++;
	}
	num_tokens = process_tokens(lex);
	display_info(lex);
	(void) num_tokens;
	return (1);
}