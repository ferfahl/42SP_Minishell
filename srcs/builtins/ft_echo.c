/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 19:24:34 by feralves          #+#    #+#             */
/*   Updated: 2023/05/05 13:52:13 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//with -n
void	ft_echo(void)
{
	int	i;
	int	new_line;

	i = 1;
	new_line = TRUE;
	if (g_data.cmd->cmd[i])
	{
		if (!ft_strncmp(g_data.cmd->cmd[i], "-n", 3))
		{
			new_line = FALSE;
			i++;
		}
		while (g_data.cmd->cmd[i])
		{
			ft_putstr_fd(g_data.cmd->cmd[i], 1);
			i++;
			if (g_data.cmd->cmd[i])
				ft_putstr_fd(" ", 1);
		}
	}
	if (new_line)
		ft_putstr_fd("\n", 1);
}
