/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 22:55:09 by joapedr2          #+#    #+#             */
/*   Updated: 2023/04/19 19:28:01 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

static int	recursive_function(t_cmd *cmd, int redirect)
{
	int		fd[2];
	pid_t	pid;

	if (!cmd)
		return (FALSE);
	// if (check_builtin(*(cmd)->cmd))
	// 	return (execute_builtin(cmd));
	pipe(fd);
	pid = fork();
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
		execve(cmd->path, cmd->cmd, g_data.envp_cmd);
	}
	waitpid(pid, NULL, 0);
	close(fd[1]);
	return (fd[0]);
}

int	run_command(void)
{
	int	fd;

	// validate_command(); descomprimir os $();
	fd = recursive_function(g_data.cmd, FALSE);
	(void)fd;
	// if (fd)
	// {
	// 	char *str;
	// 	while((str = get_next_line(fd)) != NULL)
	// 	{
	// 		printf("%s", str);
	// 		free(str);
	// 	}
	// }
	free_cmd();
	return (TRUE);
}

// /**
//  * @brief Function that executes the command sent by the user.
//  * @param input Command sent by the user.
//  * @return void
//  */
// void	executor(t_global *g, char *paths)
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
// 		executor_path(g, paths);
// }
