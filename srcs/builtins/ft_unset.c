/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 19:27:04 by feralves          #+#    #+#             */
/*   Updated: 2023/05/06 21:29:10 by feralves         ###   ########.fr       */
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
void	ft_unset(char **input)
{
	int		i;
	t_envp	*aux;
	char	*command;

	i = 0;
	if (!input[1])
		return ;
	while(input[i])
	{
		aux = g_data.envp;
		command = input[i];
		while (aux->next)
		{
			if (!ft_strncmp(command, aux->next->name, ft_strlen(command)))
				{
					ft_change_env(&aux);
					break ;
				}
			aux = aux->next;
		}
		i++;
	}
}
