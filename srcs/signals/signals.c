/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedr2 < joapedr2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:37:04 by joapedr2          #+#    #+#             */
/*   Updated: 2023/05/18 11:12:41 by joapedr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"

static void	handler_child(int signal)
{
	(void)signal;
	ft_putstr_fd("\n", STDOUT_FILENO);
	rl_replace_line("", 0);
}

void	signal_handler_child(void)
{
	signal(SIGINT, &handler_child);
	signal(SIGQUIT, SIG_IGN);
}

static void	handler(int signal)
{
	(void)signal;
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
