/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda_cruz <gda_cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 13:52:46 by gda_cruz          #+#    #+#             */
/*   Updated: 2023/03/06 17:11:51 by gda_cruz         ###   ########.fr       */
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

t_token	*new_token(char *content, int type)
{
	t_token	*new;

	new = (t_token *)malloc(sizeof(t_token));
	if (!new)
		return (NULL);
	new->content = content;
	new->type = type;
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
