/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:31:03 by joapedr2          #+#    #+#             */
/*   Updated: 2023/05/04 14:39:19 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_minishell	g_data;

int	terminal_loop(void)
{
	while (1)
	{
		init_data_line();
		signals_handler();
		g_data.tml_line = tml_get_pwd();
		g_data.input = readline(g_data.tml_line);
		free(g_data.tml_line);
		if (g_data.input == NULL)
			break ;
		if (*g_data.input)
		{
			add_history(g_data.input);
			if (validate_input() == FALSE)
				break ;
			run_command();
			// dup2(g_data.redir->fd_in, STDIN_FILENO);
			// dup2(g_data.redir->fd_out, STDOUT_FILENO);
			// ft_printf("fd in: %d\n", g_data.redir->fd_in);
			// ft_printf("fd out: %d\n", g_data.redir->fd_out);
			// ft_putendl_fd("mensagem", 2);
		}
		free_line();
	}
	exit_terminal();
	return (TRUE);
}

int	main(int argc, char **argv, char **envp)
{
	(void)argv;
	errno = 0;
	if (argc == 1)
	{
		init_data(envp);
		terminal_loop();
	}
	else
		terminate(ERR_ARG);
}
