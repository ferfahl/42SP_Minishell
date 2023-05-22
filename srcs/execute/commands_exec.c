/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_exec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 02:06:11 by feralves          #+#    #+#             */
/*   Updated: 2023/05/22 16:50:33 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	exeggcute(char *path, char **cmd, t_envp *mini_env)
{
	char	**envp;

	envp = ft_mini_to_envp(mini_env);
	g_data.exit_status = execve(path, cmd, envp);
	ft_printf("Error: execve failed\n");
	exit(g_data.exit_status);
}

void	exeggutor(t_cmd *cmd)
{
	int	i;

	i = 0;
	if (!cmd->path && !is_builtin(cmd->cmd[0]))
	{
		g_data.exit_status = 127;
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(cmd->cmd[0], 2);
		ft_putstr_fd(": command not found\n", 2);
		//free exit_builtin();
		return ;
	}
	while (g_data.pids[i] != 0)
		i++;
	*(g_data.pids + i) = fork();
	signal_handler_child();
	if (g_data.pids[i] == 0)
	{
		if (g_data.to_close > 0)
			close(g_data.to_close);
		clear_fds();
		if (!execute_builtin(cmd->cmd, 0))
			exeggcute(cmd->path, cmd->cmd, g_data.envp);
		exit_builtin();
	}
}
