/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decompress_tilde.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 17:29:55 by feralves          #+#    #+#             */
/*   Updated: 2023/05/09 01:44:36 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_istilde_exp(char c)
{
	if (c == '+' || c == '/' || c == '-' || c == '0')
		return (TRUE);
	return (FALSE);
}

char	*tilde_with_env(char *env)
{
	char	*aux;

	aux = ft_strdup(get_env(env));
	if (aux)
		return (aux);
	return (NULL);
}

char	*decompress_tilde(char *input, char *str)
{
	char	*temp;

	temp = NULL;
	if (input[1])
	{
		if (input[1] == '/')
			temp = ft_strdup(input + 1);
		if (!ft_istilde_exp(input[1]) || (!temp && input[2]))
		{
			free(str);
			return (input);
		}
		if ((input[1] && input[1] == '0') || (input[1] && input[1] == '+'))
			temp = tilde_with_env("PWD");
		if (input[1] && input[1] == '-')
			temp = tilde_with_env("OLDPWD");
	}
	free(input);
	if (temp)
	{
		str = ft_strjoin_free(str, temp);
		free(temp);
	}
	return (str);
}

void	check_tilde(char **input)
{
	*input = decompress_tilde(*input, ft_strdup(g_data.home));
}
