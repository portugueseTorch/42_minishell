/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda_cruz <gda_cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:55:34 by gda_cruz          #+#    #+#             */
/*   Updated: 2023/03/08 09:50:07 by gda_cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_data	g_data;

char	*get_iofiles(t_token **list, char *content)
{
	t_token	*token;
	int		flag;

	flag = list_has_content(list, content);
	if (flag == 0)
	{
		printf("No %s provided\n", content);
		return (NULL);
	}
	else if (flag == -1)
	{
		printf("Invalid syntax: No file specified\n");
		exit (EXIT_FAILURE);	// TODO: exit because there is no file specified after the redirection operator
	}
	token = search_list(list, content);
	printf("%s\n", token->next->content);
	return (token->next->content);
}

int	get_num_cmd(t_token **list)
{
	t_token	*temp;
	int		cmds;

	temp = *list;
	cmds = 0;
	while (temp)
	{
		while (temp && (temp->type != WORD && temp->type != ENV && temp->type != BIN))
			temp = temp->next;
		if (temp && (temp->type == WORD || temp->type == ENV || temp->type == BIN))
			cmds++;
		while (temp && (temp->type == WORD || temp->type == ENV || temp->type == BIN))
			temp = temp->next;
	}
	return (cmds);
}

static int	classify_tokens(t_token **list)
{
	t_token	*temp;

	temp = *list;
	while (temp)
	{
		if (is_redirector(temp->content))
		{
			temp->type = RED;
			temp = temp->next;
			temp->type = IO;
		}
		else if (!ft_strncmp(temp->content, "|", 2))
			temp->type = PIPE;
		else if (is_builtin(temp->content))
			temp->type = BIN;
		else if (temp->content[0] == '$')
			temp->type = ENV;
		else if (!ft_strncmp(temp->content, "<<", 3))
		{
			temp->type = HERE;
			temp = temp->next;
			temp->type = TERM;
		}
		else
			temp->type = WORD;
		temp = temp->next;
	}
	return (1);
}

static int	count_cmds(t_token **token)
{
	int		count;
	t_token	*temp;

	count = 0;
	temp = *token;
	while (temp)
	{
		if (temp && (temp->type != WORD && temp->type != ENV && temp->type != BIN))
			break ;
		count++;
		temp = temp->next;
	}
	return (count);
}

int	parse_command(t_token **token, int i)
{
	t_token	*temp;
	int		j;

	temp = *token;
	j = 0;
	g_data.cmds[i]->command = malloc(sizeof(char *) * (count_cmds(token) + 1));
	if (!g_data.cmds[i]->command)
		return (-1);
	while (temp)
	{
		if (temp && (temp->type != WORD && temp->type != ENV && temp->type != BIN))
			break ;
		g_data.cmds[i]->command[j] = ft_strdup(temp->content);
		temp = temp->next;
		j++;
	}
	g_data.cmds[i]->command[j] = NULL;
	return (1);
}

int	populate_cmds(t_token **list)
{
	t_token	*temp;
	int		i;
	
	temp = *list;
	i = 0;
	while (i < g_data.num_cmd && temp)
	{
		while (temp && (temp->type != WORD && temp->type != ENV && temp->type != BIN))
			temp = temp->next;
		g_data.cmds[i] = malloc(sizeof(t_cmd));
		if (!g_data.cmds[i])
			return (-1);
		if (parse_command(&temp, i) == -1)
			return (-1);
		while (temp && (temp->type == WORD || temp->type == ENV || temp->type == BIN))
			temp = temp->next;
		i++;
	}
	g_data.cmds[i] = NULL;
	return (1);
}

void	display_cmd_table(void)
{
	for (int i = 0; g_data.cmds[i]; i++)
	{
		printf("[ ");
		for (int j = 0; g_data.cmds[i]->command[j]; j++)
			printf("%s ", g_data.cmds[i]->command[j]);
		printf("]\n");
	}
}

int	parse_input(t_token **list)
{
	g_data.in_file = get_iofiles(list, "<");
	g_data.out_file = get_iofiles(list, ">");
	classify_tokens(list);
	display_lexer(list);
	g_data.num_cmd = get_num_cmd(list);
	g_data.cmds = malloc(sizeof(t_cmd *) * (g_data.num_cmd + 1));
	if (!g_data.cmds)
		return (-1);	// TODO: error_handling
	populate_cmds(list);
	display_cmd_table();
	return (1);
}