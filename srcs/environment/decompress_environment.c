/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decompress_environment.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedr2 < joapedr2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 16:27:42 by joapedr2          #+#    #+#             */
/*   Updated: 2023/05/20 20:44:33 by joapedr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"

static int	real_decompress(char **input, int end, int control)
{
	char	*init;
	char	*rest;
	char	*envp;
	char	*cont;

	if (control)
		init = ft_substr(*input, 0, control);
	else
		init = ft_strdup("");
	rest = ft_substr(*input, control + end + 1, ft_strlen(*input));
	envp = ft_substr(*input, control + 1, end);
	cont = get_env(envp);
	if (!cont)
		cont = "";
	control += ft_strlen(cont);
	free(*input);
	*input = ft_strjoin_free(init, cont);
	*input = ft_strjoin_free(*input, rest);
	free(envp);
	free(rest);
	return (control);
}

int	new_decompress_environment(char **input, int control)
{
	int		end;

	end = 0;
	while (is_varname(*(*input + control + end + 1)))
		end++;
	// if (*(*input + control + 1 == "?"))
		// special_decompress(*input, &control);
	if (end > 0)
		return (real_decompress(input, end, control));
	return (control + 1);
}

void	decompress_environment(char **input, int size)
{
	char	*aux_init;
	int		init;
	char	*temp;
	char	*envp;
	char	*cont;

	while (ft_strnstr(*input, "$", size))
	{
		init = ft_istrchr(*input, '$');
		envp = (*input + init + 1);
		cont = get_env(envp);
		if (!cont)
			cont = "";
		aux_init = ft_substr(*input, 0, init);
		temp = ft_strjoin_free(aux_init, cont);
		while (*envp && is_varname(*envp))
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
	int		control;

	index = -1;
	while (cmd[++index] != NULL)
	{
		if (cmd[index][0] == '~')
			check_tilde(&cmd[index]);
		control = ft_istrchr(cmd[index], '$');
		while (ft_strnstr(cmd[index] + control, "$", ft_strlen(cmd[index])))
			control = new_decompress_environment(&cmd[index], control);
	}
	return (TRUE);
}
