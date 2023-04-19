/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 19:24:34 by feralves          #+#    #+#             */
/*   Updated: 2023/04/19 19:24:45 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// //with -n
// void	ft_echo(t_global *g)
// {
// 	int	i;
// 	int	new_line;

// 	i = 1;
// 	new_line = TRUE;
// 	if (g->h_token->cmd[i])
// 	{
// 		if (!ft_strncmp(g->h_token->cmd[i], "-n", 3))
// 		{
// 			new_line = FALSE;
// 			i++;
// 		}
// 		while (g->h_token->cmd[i])
// 		{
// 			ft_putstr_fd (g->h_token->cmd[i], 1);
// 			i++;
// 			if (g->h_token->cmd[i])
// 				ft_putstr_fd (" ", 1);
// 		}
// 	}
// 	if (new_line)
// 		ft_putstr_fd("\n", 1);
// 	g->exit_status = 0;
// }
