/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decompress_environment.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedr2 < joapedr2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 16:27:42 by joapedr2          #+#    #+#             */
/*   Updated: 2023/05/19 17:10:59 by joapedr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"
static void	decompress_special_env(char **input, int size)
{
	char	*aux_init;
	int		init;
	char	*temp;
	char	*envp;
	char	*cont;

	init = 0;
	while (ft_strnstr(*input, "$",  size))
	{
		init = ft_istrchr(*input, '$');
		envp = (*input + init + 1);
		aux_init = ft_substr(*input, 0, init);
		cont = get_env(envp);
		if (!cont)
			cont = "";
		temp = ft_strjoin_free(aux_init, cont);
		while (*envp && *envp != '$' && !is_whitespace(*envp))
			envp++;
		if (envp)
			temp = ft_strjoin_free(temp, envp);
		free(*input);
		*input = temp;
	}
	if (*input[0] == '~')
		check_tilde(input);
}

void	decompress_environment(char **input, int size)
{
	char	*aux_init;
	int		init;
	char	*temp;
	char	*envp;
	char	*cont;

	init = 0;
	while (ft_strnstr(*input, "$",  size))
	{
		init = ft_istrchr(*input, '$');
		envp = (*input + init + 1);
		aux_init = ft_substr(*input, 0, init);
		cont = get_env(envp);
		if (!cont)
			cont = "";
		temp = ft_strjoin_free(aux_init, cont);
		while (*envp && *envp != '$' && !is_whitespace(*envp))
			envp++;
		if (envp)
			temp = ft_strjoin_free(temp, envp);
		free(*input);
		*input = temp;
	}
	if (*input[0] == '~')
		check_tilde(input);
}

int	decompress_envp(char **cmd)
{
	int		index;

	index = -1;
	while (cmd[++index] != NULL)
	{
		decompress_special_env(&cmd[index], ft_strlen(cmd[index]));
		decompress_environment(&cmd[index], ft_strlen(cmd[index]));
	}
	return (TRUE);
}
