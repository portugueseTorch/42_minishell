/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda-cruz <gda-cruz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 13:52:46 by gda_cruz          #+#    #+#             */
/*   Updated: 2023/03/07 16:10:41 by gda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_token	*get_last_token(t_token **list)
{
	t_token *temp;

	if (!list || !*list)
		return (NULL);
	temp = *list;
	while (temp->next)
		temp = temp->next;
	return (temp);
}

t_token	*new_token(char *content, int quotes)
{
	t_token	*new;

	new = (t_token *)malloc(sizeof(t_token));
	if (!new)
		return (NULL);
	new->content = content;
	new->quotes = quotes;
	new->type = 0;
	new->next = NULL;
	new->previous = NULL;
	return (new);
}

void	add_token(t_token **list, t_token *new)
{
	t_token	*last;

	if (!list || !new)
		return ;
	if (!*list)
	{
		*list = new;
		return ;
	}
	last = get_last_token(list);
	last->next = new;
	new->previous = last;
}

int	get_list_length(t_token **list)
{
	int	length;
	t_token *temp;

	if (!list || !*list)
		return (0);
	length = 0;
	temp = *list;
	while (temp)
	{
		temp = temp->next;
		length++;
	}
	return (length);
}

t_token	*search_list(t_token **list, char *content)
{
	t_token *temp;

	if (!list || !*list)
		return (NULL);
	temp = *list;
	while (temp)
	{
		if (!ft_strncmp(temp->content, content, ft_strlen(content)))
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}

int	list_has_content(t_token **list, char *content)
{
	t_token *temp;

	if (!list || !*list)
		return (-1);
	temp = *list;
	while (temp)
	{
		if (!ft_strncmp(temp->content, content, ft_strlen(content)))
		{
			if (temp->next && temp->next->content[0])
				return (1);
			else
				return (-1);
		}
		temp = temp->next;
	}
	return (0);
}
