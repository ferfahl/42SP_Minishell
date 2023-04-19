/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedr2 < joapedr2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:37:04 by joapedr2          #+#    #+#             */
/*   Updated: 2023/04/13 00:42:48 by joapedr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"

void	handler_child(int signal)
{
	if (signal == SIGINT)
	{
		printf("===========Entrou======\n");
		exit(1);
	}
}

static void	handler(int signal, siginfo_t *info, void *ucontext)
{
	(void)ucontext;
	if (info->si_pid)
		g_data.pid = info->si_pid;
	if (signal == SIGINT)
	{
		printf("\n");
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}

void	signals_handler(void)
{
	sigset_t	block_mask;

	sigemptyset(&block_mask);
	sigaddset(&block_mask, SIGINT);
	g_data.sa_signal.sa_mask = block_mask;
	g_data.sa_signal.sa_flags = SA_SIGINFO | SA_RESTART;
	g_data.sa_signal.sa_sigaction = handler;
	sigaction(SIGINT, &(g_data).sa_signal, NULL);
	signal(SIGQUIT, SIG_IGN);
}	