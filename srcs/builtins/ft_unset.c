/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 19:27:04 by feralves          #+#    #+#             */
/*   Updated: 2023/05/05 12:50:30 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_change_env(t_envp **mini_env)
{
	t_envp	*aux;

	aux = (*mini_env)->next;
	(*mini_env)->next = aux->next;
	free(aux->name);
	free(aux->cont);
	free(aux);
}

//with no options
void	ft_unset(void)
{
	t_envp	*aux;
	char	*command;

	aux = g_data.envp;
	if (!g_data.cmd->cmd[1])
		return ;
	command = g_data.cmd->cmd[1];
	while (aux->next)
	{
		if (!ft_strncmp(command, aux->next->name, ft_strlen(command)))
			return (ft_change_env(&aux));
		aux = aux->next;
	}
}
