/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 19:20:35 by feralves          #+#    #+#             */
/*   Updated: 2023/05/01 14:25:04 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	terminate(char *s)
{
	if (errno > 0)
		perror(s);
	else
		ft_putendl_fd(s, 2);
	exit(1);
}

void	exit_terminal(void)
{
	free_envp();
	ft_free_array(g_data.path);
	free(g_data.tml_host);
	g_data.loop = FALSE;
	rl_clear_history();
}
