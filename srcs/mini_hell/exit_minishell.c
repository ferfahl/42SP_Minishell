/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 19:20:35 by feralves          #+#    #+#             */
/*   Updated: 2023/05/18 14:10:20 by feralves         ###   ########.fr       */
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

void	exit_line(char *s, int n)
{
	free_line();
	ft_putendl_fd(s, 2);
	g_data.exit_code = n;
}

void	terminate(char *s)
{
	if (errno > 0)
		perror(s);
	else
		ft_putendl_fd(s, 2);
	exit(1);
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
