/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda_cruz <gda_cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:07:43 by gda_cruz          #+#    #+#             */
/*   Updated: 2023/03/09 15:57:18 by gda_cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	modify_value(t_list **list, char *old_value, char *new_value)
{
	t_list	*temp;

	if (!*list)
		return ;
	temp = *list;
	while (temp)
	{
		if (!ft_strncmp(temp->value, old_value, ft_strlen(old_value)))
		{
			free(temp->value);
			temp->value = new_value;
			return ;
		}
		temp = temp->next;
	}	
}

int	list_has_value(char *value, t_list **list)
{
	t_list	*temp;

	if (!*list)
		return (0);
	temp = *list;
	while (temp)
	{
		if (!ft_strncmp(temp->value, value, ft_strlen(value)))
			return (1);
		temp = temp->next;
	}
	return (0);
}
