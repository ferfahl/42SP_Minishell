/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_environment.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 10:55:19 by feralves          #+#    #+#             */
/*   Updated: 2023/05/09 00:46:58 by feralves         ###   ########.fr       */
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

// void	free_ptr(void **ptr)
// {
// 	if (*ptr != NULL)
// 	{
// 		free(*ptr);
// 		*ptr = NULL;
// 	}
// }

// void	free_envp(void)
// {
// 	t_envp	*aux;

// 	while (g_data.envp->next)
// 	{
// 		aux = g_data.envp;
// 		free_ptr((void **)&g_data.envp->cont);
// 		free_ptr((void **)&g_data.envp->name);
// 		g_data.envp = g_data.envp->next;
// 		free_ptr((void **)&aux);
// 	}
// 	free_ptr((void **)&g_data.envp->cont);
// 	free_ptr((void **)&g_data.envp->name);
// 	free_ptr((void **)&g_data.envp);
// }