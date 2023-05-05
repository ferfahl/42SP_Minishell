/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_builtin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 15:59:13 by feralves          #+#    #+#             */
/*   Updated: 2023/05/05 18:20:22 by feralves         ###   ########.fr       */
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

int	execute_builtin(char *input)
{
	(void)type;
	if (!ft_strncmp(input, "echo", 5))
		ft_echo();
	else if (!ft_strncmp(input, "cd", 3))
		ft_cd();
	else if (!ft_strncmp(input, "pwd", 4))
		ft_pwd();
	else if (!ft_strncmp(input, "export", 7))
		ft_export();
	else if (!ft_strncmp(input, "unset", 6))
		ft_unset();
	else if (!ft_strncmp(input, "env", 4))
		ft_env();
	else if (!ft_strncmp(input, "exit", 5))
		ft_exit();
	else
		return (FALSE);
	return (TRUE);
}
