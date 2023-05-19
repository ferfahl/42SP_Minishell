/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decompress_environment.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedr2 < joapedr2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 16:27:42 by joapedr2          #+#    #+#             */
/*   Updated: 2023/05/19 11:29:15 by joapedr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"

void	decompress_environment(char **input, int size)
{
	char	*aux_init;
	int		init;
	char	*temp;
	char	*envp;
	char	*cont;

	init = 0;
	while (ft_strnstr(*(input + init), "$", size))
	{
		init = ft_istrchr(*input, '$');
		envp = (*input + init + 1);
		cont = get_env(envp);
		aux_init = ft_substr(*input, 0, init);
		if (cont)
			temp = ft_strjoin_free(aux_init, cont);
		if (ft_strncmp(envp, "?", 2) == 0)
			temp = ft_itoa(g_data.exit_status);
		while (*envp && !is_whitespace(*envp))
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
		decompress_environment(&cmd[index], ft_strlen(cmd[index]));
	return (TRUE);
}
