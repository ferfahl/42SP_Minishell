/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 19:26:31 by feralves          #+#    #+#             */
/*   Updated: 2023/04/19 19:26:38 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	append_env(t_mini_env **mini_env, char *name, char *value)
// {
// 	t_mini_env	**aux;
// 	t_mini_env	*temp;

// 	aux = mini_env;
// 	temp = (*mini_env)->next;
// 	(*aux)->next = malloc(sizeof(t_mini_env));
// 	(*aux)->next->name = ft_strdup(name);
// 	(*aux)->next->value = ft_strdup(value);
// 	(*aux)->next->next = temp;
// }

// void	ft_change_value(t_mini_env **mini_env, char *cmd)
// {
// 	(*mini_env)->value = cmd;
// }

// //with no options
// void	ft_export(t_global *g)
// {
// 	char		**command;
// 	t_mini_env	*aux;
// 	int			i;

// 	i = 0;
// 	if (!g->h_token->cmd[1])
// 		return (ft_env_from_export(g->h_token, g->mini_env));
// 	aux = g->mini_env;
// 	while (g->h_token->cmd[++i])
// 	{
// 		command = ft_var_export(g->h_token->cmd[i]);
// 		while (aux->next->next)
// 		{
// 			if (!ft_strncmp(command[0], aux->name, ft_strlen(command[0])))
// 				return (ft_change_value(&aux, command[1]));
// 			aux = aux->next;
// 		}
// 		if (!ft_strncmp(command[0], aux->name, ft_strlen(command[0])))
// 			return (ft_change_value(&aux, command[1]));
// 		append_env(&aux, command[0], command[1]);
// 		ft_free_array(command);
// 	}
// }
