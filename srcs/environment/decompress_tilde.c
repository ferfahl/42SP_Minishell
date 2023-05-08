/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decompress_tilde.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 17:29:55 by feralves          #+#    #+#             */
/*   Updated: 2023/05/06 21:07:25 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_istilde_exp(char c)
{
	if (c == '+' || c == '/' || c == '-' || c == '0')
		return (TRUE);
	return (FALSE);

}

char	*tilde_with_env(char *str, char *env)
{
	char	*aux;

	aux = ft_strdup(get_env(g_data.envp, env));
	if (aux)
		return (aux);
	return (str);
}

char	*decompress_tilde(char *input)
{
	char	*str;
	char	*temp;

	temp = NULL;
	str = ft_strdup(g_data.home);
	if (input[1])
	{
		if (input[1] == '/')
			temp = ft_strjoin(str, input + 1);
		if (!ft_istilde_exp(input[1]) || input[2])
		{
			free(str);
			return (input);
		}
		if ((input[1] && input[1] == '0') || (input[1] && input[1] == '+'))
			temp = tilde_with_env(str, "PWD");
		if (input[1] && input[1] == '-')
			temp = tilde_with_env(str, "OLDPWD");
	}
	free(input);
	if (temp)
	{
		free(str);
		return (temp);
	}
	return (str);
}

void	check_tilde(char **input)
{
	*input = decompress_tilde(*input);
}
