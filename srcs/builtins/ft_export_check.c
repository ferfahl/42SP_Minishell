/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 19:25:27 by feralves          #+#    #+#             */
/*   Updated: 2023/05/08 23:29:36 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_varname(char c)
{
	return (ft_isalnum(c) || c == '_');
}

int	check_valid_var(char *name)
{
	int	i;

	i = 0;
	if (!ft_isalpha(name[i]))
		return (FALSE);
	while (name[i])
	{
		if (!is_varname(name[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

char	**ft_var_export(char *cmd)
{
	char	**command;

	command = ft_split(cmd, '=');
	if (!check_valid_var(command[0]))
		return (NULL);
	if (!command[1])
	{
		free(command[0]);
		free(command);
		command = malloc(sizeof(char *) * 3);
		command[0] = ft_strdup(cmd);
		command[1] = ft_strdup("");
		command[2] = NULL;
	}
	return (command);
}
