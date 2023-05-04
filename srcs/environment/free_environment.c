/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_enviroment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 10:55:19 by feralves          #+#    #+#             */
/*   Updated: 2023/05/04 10:55:37 by feralves         ###   ########.fr       */
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
		free(aux->name);
		free(aux->cont);
		free(aux);
		aux = temp;
		temp = NULL;
	}
	g_data.envp = NULL;
}
