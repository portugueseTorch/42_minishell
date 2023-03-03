/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda_cruz <gda_cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:37:02 by gda_cruz          #+#    #+#             */
/*   Updated: 2023/03/02 19:18:15 by gda_cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	display_info(t_token **list)
{
	t_token *temp = *list;
	for (; temp; temp = temp->next)
	{
		printf("{ Content: %s\n Type: %d\n", temp->content, temp->type);
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

int	init_shell(t_token **token)
{
	char	*raw_input;
	char	*input;

	*token = NULL;
	while (1)
	{
		raw_input = readline("\033[1;34mminishell\033[0m$ ");
		input = ft_strtrim(raw_input, " ");
		free(raw_input);
		parse_input(input, token);
		display_info(token);
	}
}

int	main(int argc, char **argv, char **envp)
{
	(void) argc;
	(void) argv;
	(void) envp;
	t_token	*token;
	init_shell(&token);
	return (0);
}