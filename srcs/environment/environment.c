/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:49:16 by joapedr2          #+#    #+#             */
/*   Updated: 2023/05/04 10:55:40 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"

static int	new_node_envp(char *str)
{
	t_envp	*new;
	t_envp	*last;
	int		size_name;

	size_name = 0;
	new = (t_envp *)malloc(sizeof(t_envp));
	if (!new)
		return (FALSE);
	while (str[size_name] && str[size_name] != '=')
		size_name++;
	new->name = ft_substr(str, 0, size_name);
	new->cont = ft_substr(str, size_name + 1, ft_strlen(str) - size_name - 1);
	new->next = NULL;
	if (!new->name || !new->cont)
		return (FALSE);
	if (g_data.envp != NULL)
	{
		last = g_data.envp;
		while (last->next != NULL)
			last = last->next;
		last->next = new;
	}
	else
		g_data.envp = new;
	return (TRUE);
}

int	init_envp(char **envp)
{
	int	i;

	i = -1;
	g_data.envp = NULL;
	while (envp[++i] != NULL)
	{
		if (!new_node_envp(envp[i]))
		{
			free_envp();
			return (FALSE);
		}
	}
	return (TRUE);
}
