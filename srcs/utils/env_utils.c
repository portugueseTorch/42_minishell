/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda_cruz <gda_cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 11:37:13 by gda_cruz          #+#    #+#             */
/*   Updated: 2023/03/09 16:59:32 by gda_cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	*get_env_value(char *value)
{
	t_list	*temp;

	if (!*(g_data.env))
		return ("");
	temp = *(g_data.env);
	while (temp)
	{
		if (!ft_strncmp(temp->value, value, ft_strlen(value)))
			return (temp->value + ft_strlen(value));
		temp = temp->next;
	}
	return ("");
}
