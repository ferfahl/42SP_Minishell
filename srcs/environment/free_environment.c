/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_environment.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 10:55:19 by feralves          #+#    #+#             */
/*   Updated: 2023/05/09 15:11:23 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_envp(void)
{
	t_envp	*aux;
	t_envp	*temp;

	aux = g_data.envp;
	while (aux)
	{
		if (aux->next)
			temp = aux->next;
		free(aux->cont);
		free(aux->name);
		free(aux);
		aux = temp;
		temp = NULL;
	}
	g_data.envp = NULL;
}
