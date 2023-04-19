/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 19:27:04 by feralves          #+#    #+#             */
/*   Updated: 2023/04/19 19:27:14 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	ft_change_env(t_mini_env **mini_env)
// {
// 	t_mini_env	*aux;

// 	aux = (*mini_env)->next;
// 	(*mini_env)->next = aux->next;
// 	free(aux->name);
// 	free(aux->value);
// 	free(aux);
// }

// //with no options
// void	ft_unset(t_global *g)
// {
// 	t_mini_env	*aux;
// 	char		*command;

// 	aux = g->mini_env;
// 	g->h_token->path = ft_strdup("minishell/path");
// 	if (!g->h_token->cmd[1])
// 		return ;
// 	command = g->h_token->cmd[1];
// 	while (aux->next)
// 	{
// 		if (!ft_strncmp(command, aux->next->name, ft_strlen(command)))
// 			return (ft_change_env(&aux));
// 		aux = aux->next;
// 	}
// }
