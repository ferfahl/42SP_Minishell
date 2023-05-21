/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedr2 < joapedr2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:37:04 by joapedr2          #+#    #+#             */
/*   Updated: 2023/05/21 15:28:58 by joapedr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"

static void	handler_child(int signal)
{
	if (signal == SIGINT)
	{
		g_data.exit_status = 130;
		ft_putstr_fd("\n", STDOUT_FILENO);
		rl_replace_line("", 0);
	}
	if (signal == SIGQUIT)
	{
		g_data.exit_status = 131;
		ft_putstr_fd("Quit (core dumped)\n", STDOUT_FILENO);
		rl_replace_line("", 0);
	}
}

void	signal_handler_child(void)
{
	signal(SIGINT, &handler_child);
	signal(SIGQUIT, &handler_child);
}

static void	handler(int signal)
{
	(void)signal;
	g_data.exit_status = 130;
	printf("\n");
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void	signals_handler(void)
{
	signal(SIGINT, &handler);
	signal(SIGQUIT, SIG_IGN);
}
