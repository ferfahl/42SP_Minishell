/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_builtin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 15:59:13 by feralves          #+#    #+#             */
/*   Updated: 2023/05/05 21:54:49 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_builtin(char *input)
{
	if (!ft_strncmp(input, "echo", 5))
		return (TRUE);
	else if (!ft_strncmp(input, "cd", 3))
		return (TRUE);
	else if (!ft_strncmp(input, "pwd", 4))
		return (TRUE);
	else if (!ft_strncmp(input, "export", 7))
		return (TRUE);
	else if (!ft_strncmp(input, "unset", 6))
		return (TRUE);
	else if (!ft_strncmp(input, "env", 4))
		return (TRUE);
	else if (!ft_strncmp(input, "exit", 5))
		return (TRUE);
	return (FALSE);
}

int	execute_builtin(char **input)
{
	if (!ft_strncmp(input[0], "echo", 5))
		ft_echo(input);
	else if (!ft_strncmp(input[0], "cd", 3))
		ft_cd(input);
	else if (!ft_strncmp(input[0], "pwd", 4))
		ft_pwd();
	else if (!ft_strncmp(input[0], "export", 7))
		ft_export(input);
	else if (!ft_strncmp(input[0], "unset", 6))
		ft_unset(input);
	else if (!ft_strncmp(input[0], "env", 4))
		ft_env(input);
	else if (!ft_strncmp(input[0], "exit", 5))
		ft_exit(input);
	else
		return (FALSE);
	return (TRUE);
}
