/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decompress_environment.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedr2 < joapedr2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 16:27:42 by joapedr2          #+#    #+#             */
/*   Updated: 2023/05/23 09:25:14 by joapedr2         ###   ########.fr       */
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

static int	special_decompress(char **input, int control)
{
	char	*init;
	char	*rest;
	char	*cont;

	if (control)
		init = ft_substr(*input, 0, control);
	else
		init = ft_strdup("");
	rest = ft_substr(*input, control + 2, ft_strlen(*input));
	cont = ft_itoa(g_data.exit_status);
	control += ft_strlen(cont);
	free(*input);
	*input = ft_strjoin_free(init, cont);
	*input = ft_strjoin_free(*input, rest);
	free(rest);
	free(cont);
	return (control);
}

int	decompress_envp(char **input, int control)
{
	int		end;

	end = 0;
	while (is_varname(*(*input + control + end + 1)))
		end++;
	if (*(*input + control + 1) == '?')
		return (special_decompress(input, control));
	if (end > 0)
		return (real_decompress(input, end, control));
	return (control + 1);
}

int	decompress_environment(void)
{
	int		index;
	int		control;
	t_cmd	*aux;

	aux = g_data.cmd;
	while (aux)
	{
		index = -1;
		while (aux->cmd[++index] != NULL)
		{
			if (aux->cmd[index][0] == '~')
				check_tilde(&aux->cmd[index]);
			control = ft_istrchr(aux->cmd[index], '$');
			while (ft_strnstr(aux->cmd[index] + control,
					"$", ft_strlen(aux->cmd[index])))
				control = decompress_envp(&(aux)->cmd[index], control);
		}
		aux = aux->next;
	}
	return (TRUE);
}
