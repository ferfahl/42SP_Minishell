/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 16:17:50 by feralves          #+#    #+#             */
/*   Updated: 2023/05/23 11:02:43 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	clear_here_doc(void)
{
	free(g_data.input);
	ft_free_array(g_data.path);
	free_redirects(&g_data.cmd->re_direct);
	if (g_data.cmd_count > 0)
		free(g_data.pids);
	free_cmd();
	free_quotes();
	free_token();
	free_list_hd();
	free_envp();
	free_redir();
	free(g_data.tml_host);
	rl_clear_history();
	exit(0);
}

static void	loop_here_doc(int *fd, char *eof)
{
	char	*input;

	input = NULL;
	while (1)
	{
		input = readline("> ");
		if (input == NULL || !ft_strncmp(input, eof, ft_strlen(eof) + 1))
		{
			free(input);
			close(fd[0]);
			print_list(fd[1]);
			close(fd[1]);
			clear_here_doc();
		}
		if (*input)
			hd_add_history(input);
		free(input);
	}
}

int	ft_here_doc(char *eof)
{
	int		pid;
	int		fd[2];

	pipe(fd);
	pid = fork();
	start_hd(&g_data.hdoc);
	signal_handler_child();
	if (pid == -1)
		terminate(ERR_FORK);
	if (pid == 0)
	{
		signal_handler_heredoc();
		loop_here_doc(fd, eof);
	}
	waitpid(pid, NULL, 0);
	signals_handler();
	free_list_hd();
	close(fd[1]);
	return (fd[0]);
}
