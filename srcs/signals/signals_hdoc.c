/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_hdoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedr2 < joapedr2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 10:47:03 by feralves          #+#    #+#             */
/*   Updated: 2023/05/19 12:51:38 by joapedr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	signint_doc(int sig)
{
	if (sig == SIGINT)
	{
		g_data.exit_status = 130;
		dprintf(2, "\n");
		clear_here_doc();
	}
}

void	signal_handler_heredoc(void)
{
	signal(SIGINT, signint_doc);
	signal(SIGQUIT, SIG_IGN);
}
