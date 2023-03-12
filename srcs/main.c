/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda_cruz <gda_cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:37:02 by gda_cruz          #+#    #+#             */
/*   Updated: 2023/03/11 19:12:46 by gda_cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

// Global Variable
t_data	g_data;

static void	reset_global(void)
{
	g_data.child = FALSE;
	g_data.expanded = FALSE;
}

static void	display_info(t_lexer *lex)
{
	printf(" ------------------------------- \n");
	printf("|          Lexer Info           |\n");
	printf(" ------------------------------- \n");

	for (; lex->token_list; lex->token_list = lex->token_list->next)
	{
		printf("Content: %s\nType: %d\n", lex->token_list->content, lex->token_list->type);
		printf(" ------------------------------- \n");
	}
}

static void	process_input(char *input)
{
	t_lexer	lex;

	if (input_is_empty(input))
	{
		free(input);
		return ;
	}
	if (lexer(input, &lex) <= 0)
		return ;
	display_info(&lex);
}

int	main(int argc, char **argv, char **envp)
{
	char	*input;

	(void) argc;
	(void) argv;
	init_shell(envp);
	while (1)
	{
		reset_global();
		input = read_input();
		if (!input)
			exit (EXIT_FAILURE); // TODO: get exit codes correctly and free stuff if needed
		if (ft_strlen(input) <= 0)
		{
			free(input);
			continue ;
		}
		if (!input_is_empty(input))
			add_history(input); // FIXME: shell line is overlapping command, for some reason
		process_input(input);
	}
}