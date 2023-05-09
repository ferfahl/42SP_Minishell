/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 19:26:31 by feralves          #+#    #+#             */
/*   Updated: 2023/05/09 01:15:07 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	append_env(t_envp **mini_env, char *name, char *cont)
{
	t_envp	**aux;
	t_envp	*temp;

	aux = mini_env;
	temp = (*mini_env)->next;
	(*aux)->next = malloc(sizeof(t_envp));
	(*aux)->next->name = ft_strdup(name);
	(*aux)->next->cont = ft_strdup(cont);
	(*aux)->next->next = temp;
}

static void	ft_change_cont(t_envp **mini_env, char *cmd)
{
	free((*mini_env)->cont);
	(*mini_env)->cont = cmd;
}

void	export_valid(char *input)
{
	char	**command;
	char	*cmd;
	t_envp	*aux;

	aux = g_data.envp;
	command = ft_var_export(input);
	if (!ft_strlen(command[1]))
		return (ft_free_array(command));
	while (aux)
	{
		if (!ft_strncmp(command[0], aux->name, ft_strlen(command[0])))
		{
			cmd = ft_strdup(command[1]);
			ft_free_array(command);
			return (ft_change_cont(&aux, cmd));
		}
		if (!aux->next)
			break ;
		aux = aux->next;
	}
	append_env(&aux, command[0], command[1]);
	ft_free_array(command);
}

void	ft_export(char **input)
{
	int		i;

	i = 0;
	if (!input[1])
		return (ft_env_from_export(input));
	while (input[++i])
	{
		while (input[i] && check_export_error(input[i]))
			i++;
		if (!input[i])
			return ;
		export_valid(input[i]);
	}
}
