/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 19:23:49 by feralves          #+#    #+#             */
/*   Updated: 2023/05/05 13:52:07 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_env(t_envp *env, char *key)
{
	t_envp	*tmp;

	tmp = env;
	while (tmp)
	{
		if (!ft_strncmp(tmp->name, key, ft_strlen(key) + 1))
			return (tmp->cont);
		tmp = tmp->next;
	}
	return (NULL);
}

void	ft_cd(void)
{
	if (g_data.cmd->cmd[1] == NULL)
	{
		chdir(get_env(g_data.envp, "HOME"));
		return ;
	}
	chdir(g_data.cmd->cmd[1]);
}
