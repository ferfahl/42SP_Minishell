/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decompress_tilde.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 17:29:55 by feralves          #+#    #+#             */
/*   Updated: 2023/05/06 18:18:30 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_istilde_exp(char c)
{
	if (c == '+' || c == '/' || c == '-' || c == '0')
		return (TRUE);
	return (FALSE);

}

char	*tilde_with_env(char *str, char *input, char *env)
{
	char	*aux;

	if (input[2])
		return (input);
	aux = ft_strdup(get_env(g_data.envp, env));
	if (!aux)
		return (input);
	str = ft_strjoin_free(str, aux);
	free(aux);
	return (str);
}

char	*decompress_tilde(char *input)
{
	char	*str;

	if (input[1] && !ft_istilde_exp(input[1]))
		return (input);
	str = ft_strdup(g_data.home);
	if (input[1] && input[1] == '/')
		str = ft_strjoin_free(str, input + 1);
	else if ((input[1] && input[1] == '0') || (input[1] && input[1] == '+'))
		str = tilde_with_env(str, input, "PWD");
	else if (input[1] && input[1] == '-')
		str = tilde_with_env(str, input, "OLDPWD");
	return (str);
}

void	check_tilde(char **input)
{
	*input = decompress_tilde(*input);
}
