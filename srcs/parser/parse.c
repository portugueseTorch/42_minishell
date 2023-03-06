/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gda_cruz <gda_cruz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:55:34 by gda_cruz          #+#    #+#             */
/*   Updated: 2023/03/06 19:33:07 by gda_cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	parse_input(t_token **list)
{
	g_data->num_cmd;
	g_data->cmds = malloc(sizeof(t_cmd) * g_data->num_cmd);
	if (!g_data->cmds)
		return (-1);	// TODO: error_handling
	populate_cmds(list);
}