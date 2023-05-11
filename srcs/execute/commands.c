/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 22:55:09 by joapedr2          #+#    #+#             */
/*   Updated: 2023/05/11 17:09:14 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

void	exeggcute(char *path, char **cmd, t_envp *mini_env)
{
	int		check;
	char	**envp;

	envp = ft_mini_to_envp(mini_env);
	check = execve(path, cmd, envp);
	ft_printf("Error: execve failed\n");
	exit(check);
}

// int	is_empty_2(char *cmd)
// {
// 	int	i;
// 	int	len;

// 	i = 0;
// 	len = ft_strlen(cmd);
// 	while(cmd[i])
// 	{
// 		if (is_whitespace(cmd[i]))
// 			len--;
// 		i++;
// 	}
// 	if (len == 0)
// 		return (TRUE);
// 	return (FALSE);
// }

// char	**replace_cmd(char **cmd)
// {
// 	int		i;
// 	char	**aux;

// 	i = 0;
// 	aux = cmd;
// 	while (cmd[i])
// 	{
		
// 		i++;
// 	}
// }

static int	recursive_function(t_cmd *cmd, int redirect)
{
	int		fd[2];
	pid_t	pid;

	if (g_data.redir->has_redir)
	{
		redirections_handle(cmd->cmd);
		// if (is_empty_2(cmd->cmd[0]))
		// {
		// 	replace_cmd(cmd->cmd);
		// }
	}
	if (!cmd)
		return (FALSE);
	if (!cmd->path && !is_builtin(cmd->cmd[0]))
	{
		ft_printf("minishell: %s: command not found\n", cmd->cmd[0]);
		return (FALSE);
	}
	pipe(fd);
	pid = fork();
	signal_handler_child();
	if (pid == -1)
		terminate(ERR_FORK);
	if (pid == 0)
	{
		if (dup2(recursive_function(cmd->next, TRUE), fd[0]))
			dup2(fd[0], STDIN_FILENO);
		else
			close(fd[0]);
		if (redirect)
			dup2(fd[1], STDOUT_FILENO);
		else
			close(fd[1]);
		if (!execute_builtin(cmd->cmd))
			exeggcute(cmd->path, cmd->cmd, g_data.envp);
		exit_builtin();
	}
	waitpid(pid, NULL, 0);
	dup2(g_data.redir->fd_in, STDIN_FILENO);
	dup2(g_data.redir->fd_out, STDOUT_FILENO);
	close(fd[1]);
	return (fd[0]);
}

int	run_command(void)
{
	int		fd;
	t_cmd	*aux;

	aux = g_data.cmd;
	while (aux != NULL)
	{
		decompress_envp(aux->cmd);
		decompress_quotes(aux->cmd);
		aux = aux->next;
	}
	if (!g_data.cmd->next && is_builtin(g_data.cmd->cmd[0]))
		return (execute_builtin(g_data.cmd->cmd));
	fd = recursive_function(g_data.cmd, FALSE);
	(void)fd;
	free_quotes();
	free_cmd();
	return (TRUE);
}

	// validate_command(); descomprimir os $(); -> vai ser feito antes
	// if (fd)
	// {
	// 	char *str;
	// 	while((str = get_next_line(fd)) != NULL)
	// 	{
	// 		printf("%s", str);
	// 		free(str);
	// 	}
	// }
