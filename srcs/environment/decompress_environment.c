/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decompress_environment.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 16:27:42 by joapedr2          #+#    #+#             */
/*   Updated: 2023/05/06 18:17:12 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"

static char	*find_envp(char *name)
{
	t_envp	*aux;

	aux = g_data.envp;
	while (aux != NULL)
	{
		if (!ft_strncmp(aux->name, name, ft_strlen(aux->name)))
			return (aux->cont);
		aux = aux->next;
	}
	return (NULL);
}

void	decompress_environment(char **input, int size)
{
	char	*aux_init;
	int		init;
	char	*temp;
	char	*envp;

	if (*input[0] == '~')
		check_tilde(input);
	while (ft_strnstr(*input, "$", size))
	{
		init = ft_istrchr(*input, '$');
		envp = (*input + init + 1);
		aux_init = ft_substr(*input, 0, init);
		temp = ft_strjoin_free(aux_init, find_envp(envp));
		while (*envp && ft_isalnum(*envp))
			envp++;
		if (envp)
			temp = ft_strjoin_free(temp, envp);
		free(*input);
		*input = temp;
	}
}

int	decompress_envp(char **cmd)
{
	int		index;

	index = -1;
	while (cmd[++index] != NULL)
		decompress_environment(&cmd[index], ft_strlen(cmd[index]));
	return (TRUE);
}
