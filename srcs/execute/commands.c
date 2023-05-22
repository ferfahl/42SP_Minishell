/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 22:55:09 by joapedr2          #+#    #+#             */
/*   Updated: 2023/05/22 16:34:05 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

void	exeggcute(char *path, char **cmd, t_envp *mini_env)
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

void	run_pipe(t_cmd *cmd, int i)
{
	if (i == 0)
	{
		pipe(cmd->pipe);
		dup2(cmd->pipe[1], STDOUT_FILENO);
		close(cmd->pipe[1]);
		g_data.to_close = cmd->pipe[0];
	}
	if (i == 1)
	{
		dup2(cmd->pipe[0], STDIN_FILENO);
		dup2(g_data.redir->fd_out, STDOUT_FILENO);
		close(cmd->pipe[0]);
	}
}

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

void	run_line(t_cmd *cmd)
{
	// t_cmd	*aux;
	int		status;
	int		i;

	i = -1;
	status = 0;
	if (g_data.cmd_count > 0)
		g_data.pids = (pid_t *)ft_calloc(sizeof(pid_t), g_data.cmd_count + 1);
	// aux = cmd;
	while (cmd)
	{
		run_cmd(cmd);
		cmd = cmd->next;
		// if (hell->here_code == 1)
		// 	break ;
	}
	// free cmd
	dup2(g_data.redir->fd_in, STDIN_FILENO);
	dup2(g_data.redir->fd_out, STDOUT_FILENO);
	if (g_data.cmd_count > 0)
		while (++i <= g_data.cmd_count)
			waitpid(g_data.pids[i], &status, 0);
	if (g_data.cmd_count > 1)
		close(g_data.to_close);
	// ft_endline(status); //free end line
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

int	run_command(void)
{
	t_cmd	*aux;

	aux = g_data.cmd;
	while (aux != NULL)
	{
		decompress_envp(aux->cmd);
		decompress_quotes(aux->cmd);
		aux = aux->next;
	}
	executables_files();
	g_data.exit_status = 0;
	if (!g_data.cmd->next && is_builtin(g_data.cmd->cmd[0]))
		return (execute_builtin(g_data.cmd->cmd, 42));
	count_cmds(&g_data.cmd);
	run_line(g_data.cmd);
	free_quotes();
	return (TRUE);
}
