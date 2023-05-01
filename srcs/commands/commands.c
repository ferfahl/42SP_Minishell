/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedr2 < joapedr2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 22:55:09 by joapedr2          #+#    #+#             */
/*   Updated: 2023/05/01 16:11:22 by joapedr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

static int	recursive_function(t_cmd *cmd, int redirect)
{
	int		fd[2];
	pid_t	pid;

	if (!cmd)
		return (FALSE);
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
	t_cmd *aux;

	aux = g_data.cmd;
	while (aux != NULL)
	{
		decompress_quotes(aux->cmd);
		// decompress_envp();
		aux = aux->next;
	}
	fd = recursive_function(g_data.cmd, FALSE);
	(void)fd;
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
