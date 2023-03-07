/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda-cruz <gda-cruz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:37:02 by gda_cruz          #+#    #+#             */
/*   Updated: 2023/03/07 16:53:59 by gda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	display_lexer(t_token **list)
{
	t_token *temp = *list;
	for (; temp; temp = temp->next)
	{
		printf("\n{ Content: %s\n Type: %d\n", temp->content, temp->type);
		if (temp->previous)
			printf(" Previous: %s\n", temp->previous->content);
		else
			printf(" Previous: NULL\n");
		if (temp->next)
			printf(" Next: %s }\n\n", temp->next->content);
		else
			printf(" Next: NULL }\n\n");
	}
}

void	reset_tokens(t_token **list)
{
	t_token	*temp;
	t_token	*clean;

	temp = *list;
	while (temp)
	{
		free(temp->content);
		temp->type = 0;
		temp->previous = NULL;
		clean = temp;
		temp = temp->next;
		free(clean);
	}
	*list = NULL;
}

int	init_shell(t_token **list)
{
	char	*raw_input;
	char	*input;

	*list = NULL;
	while (1)
	{
		raw_input = readline("\033[1;34mminishell\033[0m$ ");
		input = ft_strtrim(raw_input, " ");
		free(raw_input);
		if (!lexer(input, list))
		{
			printf("Incorrect quotation\n");
			return (0);
		}
		parse_input(list);
		// display_info(list);
		reset_tokens(list);
	}
}

int	main(int argc, char **argv, char **envp)
{
	(void) argc;
	(void) argv;
	(void) envp;
	t_token	*tokens;
	init_shell(&tokens);
	return (0);
}