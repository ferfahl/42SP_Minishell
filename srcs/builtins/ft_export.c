/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 19:26:31 by feralves          #+#    #+#             */
/*   Updated: 2023/05/08 23:43:50 by feralves         ###   ########.fr       */
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

int	check_export_error(char *input)
{
	if (input[0] == '-')
	{
		ft_putstr_fd("minishell: export: ", 2);
		ft_putstr_fd(input, 2);
		ft_putstr_fd(": invalid option\n", 2);
		return (TRUE);
	}
	if (!ft_isalpha(input[0]))
	{
		ft_putstr_fd("minishell: export: `", 2);
		ft_putstr_fd(input, 2);
		ft_putstr_fd("`: not a valid identifier\n", 2);
		return (TRUE);
	}
	return (FALSE);
}

//with no options
void	ft_export(char **input)
{
	char	**command;
	t_envp	*aux;
	int		i;

	i = 0;
	if (!input[1])
		return (ft_env_from_export(input));
	while (input[++i])
	{
		if (check_export_error(input[i]))
			i++;
		if (!input[i])
			return ;
		aux = g_data.envp;
		command = ft_var_export(input[i]);
		while (aux->next)
		{
			if (!ft_strncmp(command[0], aux->name, ft_strlen(command[0])))
				return (ft_change_cont(&aux, command[1]));
			aux = aux->next;
		}
		append_env(&aux, command[0], command[1]);
		ft_free_array(command);
	}
}
