/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedr2 < joapedr2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 19:20:35 by feralves          #+#    #+#             */
/*   Updated: 2023/05/19 13:01:45 by joapedr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	clear_fds(void)
{
	int	fd;

	fd = 100;
	if (fd < 0)
		return ;
	while (fd > STDERR_FILENO)
		close(fd--);
}

void	terminate(char *s)
{
	if (errno > 0)
		perror(s);
	else
		ft_putendl_fd(s, 2);
	g_data.exit_status = 1;
	exit(g_data.exit_status);
}

void	exit_builtin(void)
{
	dup2(g_data.redir->fd_in, STDIN_FILENO);
	dup2(g_data.redir->fd_out, STDOUT_FILENO);
	free_line();
	free_envp();
	free_redir();
	free(g_data.tml_host);
	rl_clear_history();
	exit(0);
}

void	exit_terminal(void)
{
	clear_fds();
	free_line();
	free_envp();
	free_redir();
	free(g_data.tml_host);
	rl_clear_history();
}
