/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 19:26:00 by feralves          #+#    #+#             */
/*   Updated: 2023/05/05 17:22:05 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_clean_exit(int status)
{
	ft_printf("Goodbye, cadet!\n");
	exit_terminal();
	exit(status);
}

static void	ft_exit_invalid(char *input, int status, int errorno)
{
	if (errorno == 1)
		ft_putstr_fd("exit: exited with too many arguments\n", 1);
	else
	{
		ft_putstr_fd("exit: ", 1);
		ft_putstr_fd(input, 1);
		ft_putstr_fd("exited with invalid argument\n", 1);
	}
	exit_terminal();
	exit(status);
}

void	ft_exit(void)
{
	int	i;

	i = 1;
	if (g_data.cmd->cmd[1] == NULL)
		ft_clean_exit(EXIT_SUCCESS);
	else
	{
		while (g_data.cmd->cmd[i])
		{
			if (ft_isdigit_mod(g_data.cmd->cmd[i]))
				ft_clean_exit(ft_atoi_mod(g_data.cmd->cmd[1]));
			else if (g_data.cmd->cmd[2])
				ft_exit_invalid(g_data.cmd->cmd[1], 42, 1);
			else
				ft_exit_invalid(g_data.cmd->cmd[1], 2, 0);
			i++;
		}
	}
}
