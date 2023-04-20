/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:31:03 by joapedr2          #+#    #+#             */
/*   Updated: 2023/04/19 20:08:48 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_minishell	g_data;

int	terminal_loop(void)
{
	char	*input;

	while (1)
	{
		input = NULL;
		signals_handler();
		g_data.tml_line = tml_get_pwd();
		input = readline(g_data.tml_line);
		free(g_data.tml_line);
		if (input == NULL)
			break ;
		if (*input)
		{
			add_history(input);
			if (validate_input(input) == FALSE)
				break ;
			run_command();
		}
		free(input);
	}
	free(input);
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
