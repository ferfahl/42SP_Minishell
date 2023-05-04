/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:40:46 by feralves          #+#    #+#             */
/*   Updated: 2023/05/04 11:43:20 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_cmd(void)
{
	t_cmd	*aux;
	t_cmd	*temp;

	aux = g_data.cmd;
	while (aux)
	{
		temp = NULL;
		if (aux->next)
			temp = aux->next;
		ft_free_array(aux->cmd);
		free(aux->path);
		free(aux);
		aux = temp;
	}
	g_data.cmd = NULL;
}
