/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 19:26:00 by feralves          #+#    #+#             */
/*   Updated: 2023/04/19 19:26:17 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	ft_clean_exit(t_token *token, int status)
// {
// 	ft_printf("Goodbye, cadet!\n");
// 	ft_clean_mem(token);
// 	rl_clear_history();
// 	exit(status);
// }

// void	ft_exit_invalid(t_token *token, char **input, int status, int errorno)
// {
// 	if (errorno == 1)
// 		ft_printf("exit: exited with too many arguments\n");
// 	else
// 		ft_printf("exit: %s: exited with invalid argument\n", input[1]);
// 	ft_clean_mem(token);
// 	rl_clear_history();
// 	exit(status);
// }

// /**
// *@brief Checks if Minishell wants to exit.
// *@param input the input sent after the prompt
// *@return none.
// */
// void	ft_exit(t_global *g)
// {
// 	int	i;

// 	i = 1;
// 	ft_free_env(g->mini_env);
// 	if (g->h_token->cmd[1] == NULL)
// 		ft_clean_exit(g->h_token, EXIT_SUCCESS);
// 	else
// 	{
// 		while (g->h_token->cmd[i])
// 		{
// 			if (ft_isdigit_mod(g->h_token->cmd[i]))
// 				ft_clean_exit(g->h_token, ft_atoi_mod(g->h_token->cmd[1]));
// 			else if (g->h_token->cmd[2])
// 				ft_exit_invalid(g->h_token, g->h_token->cmd, 42, 1);
// 			else
// 				ft_exit_invalid(g->h_token, g->h_token->cmd, 2, 0);
// 			i++;
// 		}
// 	}
// }
