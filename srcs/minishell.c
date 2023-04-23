/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:31:03 by joapedr2          #+#    #+#             */
/*   Updated: 2023/04/23 11:01:44 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_minishell	g_data;

int	terminal_loop(void)
{
	char	*input;

	input = NULL;
	while (1)
	{
		signals_handler();
		g_data.tml_line = tml_get_pwd();
		free(input);
		input = readline(g_data.tml_line);
		free(g_data.tml_line);
		if (input == NULL)
			break ;
		if (*input)
		{
			add_history(input);
			if (validate_input(input) == FALSE)
				break ;
			if (g_data.redir == FALSE)
				run_command();
			else
				ft_printf("Needs a function to redirect!\n");
		}
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
