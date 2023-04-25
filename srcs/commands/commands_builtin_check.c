/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_builtin_check.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 15:59:13 by feralves          #+#    #+#             */
/*   Updated: 2023/04/21 16:00:09 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

// /**
//  * @brief Function that executes the command sent by the user.
//  * @param input Command sent by the user.
//  * @return void
//  */
// void	execute_builtin(t_global *g, char *paths)
// {
// 	char	*input;

// 	input = g->h_token->cmd[0];
// 	if (!ft_strncmp(input, "echo", 5))
// 		ft_echo(g);
// 	else if (!ft_strncmp(input, "cd", 3))
// 		ft_cd(g);
// 	else if (!ft_strncmp(input, "pwd", 4))
// 		ft_pwd(g);
// 	else if (!ft_strncmp(input, "export", 7))
// 		ft_export(g);
// 	else if (!ft_strncmp(input, "unset", 6))
// 		ft_unset(g);
// 	else if (!ft_strncmp(input, "env", 4))
// 		ft_env(g);
// 	else if (!ft_strncmp(input, "exit", 5))
// 		ft_exit(g);
// 	else
// 		return ;
// }
