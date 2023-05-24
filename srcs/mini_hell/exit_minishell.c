/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedr2 < joapedr2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 19:20:35 by feralves          #+#    #+#             */
/*   Updated: 2023/05/24 14:49:11 by joapedr2         ###   ########.fr       */
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
	// ft_putstr_fd("\n\t\t=================================\n", STDOUT_FILENO);
	// ft_putstr_fd("\t\t|\tGoodbye, cadet!\t\t|\n", STDOUT_FILENO);
	// ft_putstr_fd("\t\t=================================\n\n", STDOUT_FILENO);
}
