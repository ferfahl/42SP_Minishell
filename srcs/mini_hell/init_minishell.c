/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:39:11 by joapedr2          #+#    #+#             */
/*   Updated: 2023/05/17 15:17:23 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	init_path(void)
{
	t_envp	*temp;

	g_data.path = NULL;
	temp = g_data.envp;
	while (temp->next && ft_strncmp(temp->name, "PATH", 4))
		temp = temp->next;
	if (temp == NULL)
		return (FALSE);
	g_data.path = ft_split(temp->cont, ':');
	if (!g_data.path)
		terminate(ERR_PATH_ALLOC);
	return (TRUE);
}

void	ft_start_fds(void)
{
	t_redirect	*new;

	new = (t_redirect *)malloc(sizeof(t_redirect));
	new->fd_in = dup(STDIN_FILENO);
	new->fd_out = dup(STDOUT_FILENO);
	new->head_redir = NULL;
	// new->head_redir->symbol = NULL;
	// new->head_redir->key_word = NULL;
	// new->head_redir->next = NULL;
	g_data.redir = new;
}

void	init_data_line(void)
{
	g_data.exit_code = 0;
	g_data.tml_line = NULL;
	g_data.input = NULL;
	g_data.tokens = NULL;
	g_data.cmd = NULL;
	g_data.quotes = NULL;
	g_data.hdoc = NULL;
	init_path();
}

int	init_data(char **envp)
{
	if (!init_envp(envp))
		terminate(ERR_ENVP_ALLOC);
	ft_start_fds();
	g_data.tml_host = tml_user_and_host();
	g_data.home = get_env("HOME");
	if (!g_data.tml_host)
		terminate(ERR_HOSTNAME_ALLOC);
	return (TRUE);
}
