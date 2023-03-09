/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda_cruz <gda_cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:37:02 by gda_cruz          #+#    #+#             */
/*   Updated: 2023/03/09 17:01:52 by gda_cruz         ###   ########.fr       */
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
		printf("%s\n", input);
		free(input);
	}
}