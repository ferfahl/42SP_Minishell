/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedr2 < joapedr2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:39:11 by joapedr2          #+#    #+#             */
/*   Updated: 2023/04/13 01:02:55 by joapedr2         ###   ########.fr       */
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

static int	init_path(void)
{
	t_envp	*temp;

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

int	init_data(char **envp)
{
	if (!init_envp(envp))
		terminate(ERR_ENVP_ALLOC);
	g_data.path = NULL;
	if (!init_path())
		terminate(ERR_PATH_NFOUND);
	g_data.envp_cmd = envp;
	g_data.loop = TRUE;
	g_data.cmd = NULL;
	g_data.tml_line = NULL;
	g_data.tml_host = tml_user_and_host();
	if (!g_data.tml_host)
		terminate(ERR_HOSTNAME_ALLOC);
	return (TRUE);
}
