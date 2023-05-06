/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 19:23:49 by feralves          #+#    #+#             */
/*   Updated: 2023/05/05 21:51:53 by feralves         ###   ########.fr       */
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

void	ft_cd(char **input)
{
	if (!input[1])
	{
		chdir(get_env(g_data.envp, "HOME"));
		return ;
	}
	chdir(input[1]);
}
