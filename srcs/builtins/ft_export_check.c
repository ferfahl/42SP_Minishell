/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 19:25:27 by feralves          #+#    #+#             */
/*   Updated: 2023/05/09 01:54:44 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_varname(char c)
{
	return (ft_isalnum(c) || c == '_');
}

static int	check_valid_var(char *name)
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

static int	print_export_error(char *input, char *message, int code)
{
	ft_putstr_fd("minishell: export: ", 2);
	if (code == 2)
		ft_putstr_fd("`", 2);
	ft_putstr_fd(input, 2);
	if (code == 2)
		ft_putstr_fd("'", 2);
	ft_putendl_fd(message, 2);
	return (TRUE);
}

int	check_export_error(char *input)
{
	int	i;

	i = 0;
	if (input[i] == '=')
		return (print_export_error(input, ": not a valid identifier", 2));
	while (input[i] && input[i] != '=')
	{
		if (input[0] == '-')
			return (print_export_error(input, ": invalid option", 42));
		if (!is_varname(input[i]) || !ft_isalpha(input[0]))
			return (print_export_error(input, ": not a valid identifier", 2));
		i++;
	}
	return (FALSE);
}
