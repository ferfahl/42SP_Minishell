/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_for_execve.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 10:56:19 by feralves          #+#    #+#             */
/*   Updated: 2023/05/17 16:13:17 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	minienv_size(t_envp *mini_env)
{
	size_t	size;
	t_envp	*aux;

	size = 0;
	aux = mini_env;
	while (aux)
	{
		size++;
		aux = aux->next;
	}
	return (size);
}

static char	*append_mini_env(char *first, char *last)
{
	char	*temp;
	char	*result;

	temp = ft_strjoin_mod(first, "=");
	result = ft_strjoin_mod(temp, last);
	free(temp);
	return (result);
}

char	**ft_mini_to_envp(t_envp *mini_env)
{
	t_envp	*temp;
	char	**new_envp;
	int		i;

	temp = mini_env;
	i = 0;
	new_envp = malloc(sizeof(char *) * (minienv_size(mini_env) + 1));
	if (!new_envp)
		return (NULL);
	while (temp->next)
	{
		new_envp[i] = append_mini_env(temp->name, temp->cont);
		i++;
		temp = temp->next;
	}
	new_envp[i] = append_mini_env(temp->name, temp->cont);
	i++;
	new_envp[i] = NULL;
	return (new_envp);
}
