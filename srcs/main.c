/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda_cruz <gda_cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:37:02 by gda_cruz          #+#    #+#             */
/*   Updated: 2023/03/08 17:24:59 by gda_cruz         ###   ########.fr       */
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