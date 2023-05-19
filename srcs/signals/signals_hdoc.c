/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_hdoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 10:47:03 by feralves          #+#    #+#             */
/*   Updated: 2023/05/18 10:47:20 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	signint_doc(int sig)
{
	if (sig == SIGINT)
	{
		dprintf(2, "\n");
		clear_here_doc();
	}
}

void	signal_handler_heredoc(void)
{
	signal(SIGINT, signint_doc);
	signal(SIGQUIT, SIG_IGN);
}
