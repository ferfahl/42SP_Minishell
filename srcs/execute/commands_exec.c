/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_exec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 02:06:11 by feralves          #+#    #+#             */
/*   Updated: 2023/05/24 20:02:09 by feralves         ###   ########.fr       */
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

static void	exec_error(char *str)
{
	g_data.exit_status = 127;
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": command not found\n", 2);
}

void	exeggutor(t_cmd *cmd)
{
	int	i;

	if (!cmd->path && cmd->cmd[0] && !is_builtin(cmd->cmd[0]))
		return (exec_error(cmd->cmd[0]));
	i = 0;
	while (g_data.pids[i] != 0)
		i++;
	*(g_data.pids + i) = fork();
	signal_handler_child();
	if (g_data.pids[i] == 0)
	{
		if (g_data.to_close > 0)
			close(g_data.to_close);
		clear_fds();
		free(g_data.pids);
		if (!execute_builtin(cmd->cmd, 0))
			exeggcute(cmd->path, cmd->cmd, g_data.envp);
		exit_builtin();
	}
}
