/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:49:16 by joapedr2          #+#    #+#             */
/*   Updated: 2023/04/30 19:41:46 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"

char	*descompress_environment(char *input, int size)
{
	char	*new;
	int		init;
	char	*envp;
	t_envp	*aux;

	new = input;
	while (ft_strnstr(new, "$", size))
	{
		init = ft_istrchr(new, '$');
		envp = (new + init + 1);
		aux = g_data.envp;
		while (aux->next != NULL)
		{
			if (!ft_strncmp(aux->name, envp, ft_strlen(aux->name)))
				break ;
			aux = aux->next;
		}
		new = ft_substr(new, 0, init);
		if (aux->next != NULL)
			new = ft_strjoin_free(new, aux->cont);
		while (*envp && ft_isalnum(*envp))
			envp++;
		new = ft_strjoin_free(new, envp);
	}
	return (new);
}

void	free_envp(void)
{
	t_envp	*aux;
	t_envp	*temp;

	aux = g_data.envp;
	while (aux)
	{
		if (aux->next)
			temp = aux->next;
		free(aux->name);
		free(aux->cont);
		free(aux);
		aux = temp;
		temp = NULL;
	}
	g_data.envp = NULL;
}

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
