/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 22:55:09 by joapedr2          #+#    #+#             */
/*   Updated: 2023/05/23 18:49:48 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

void	run_cmd(t_cmd *cmd)
{
	if (cmd->next)
		run_pipe(cmd, 0);
	redir_list(cmd->re_direct);
	if (cmd->cmd[0])
		exeggutor(cmd);
	if (cmd->next)
		run_pipe(cmd, 1);
}

void	run_command(t_cmd *cmd)
{
	int		status;
	int		i;

	i = -1;
	status = 0;
	if (g_data.cmd_count > 0)
		g_data.pids = (pid_t *)ft_calloc(sizeof(pid_t), g_data.cmd_count + 1);
	while (cmd)
	{
		run_cmd(cmd);
		cmd = cmd->next;
	}
	dup2(g_data.redir->fd_in, STDIN_FILENO);
	dup2(g_data.redir->fd_out, STDOUT_FILENO);
	if (g_data.cmd_count > 0)
		while (++i <= g_data.cmd_count)
			waitpid(g_data.pids[i], &status, 0);
	if (g_data.cmd_count > 1)
		close(g_data.to_close);
	if (g_data.cmd_count > 0)
		free (g_data.pids);
	if (WIFSIGNALED(status))
		g_data.exit_status = 128 + status;
	else if (WIFEXITED(status))
		g_data.exit_status = WEXITSTATUS(status);
}

void	count_cmds(t_cmd **cmd)
{
	t_cmd	*aux;
	t_cmd	*reverse;

	reverse = NULL;
	g_data.cmd_count = 0;
	while (*cmd)
	{
		redirections_handle(cmd);
		if ((*cmd)->cmd[0])
			g_data.cmd_count++;
		aux = *cmd;
		*cmd = (*cmd)->next;
		aux->next = reverse;
		reverse = aux;
	}
	*cmd = reverse;
}

int	run_line(void)
{
	decompress_environment();
	decompress_quotes();
	executables_files();
	g_data.exit_status = 0;
	if (!g_data.cmd->next && is_builtin(g_data.cmd->cmd[0]))
		return (execute_builtin(g_data.cmd->cmd, 42));
	count_cmds(&g_data.cmd);
	run_command(g_data.cmd);
	free_quotes();
	return (TRUE);
}
