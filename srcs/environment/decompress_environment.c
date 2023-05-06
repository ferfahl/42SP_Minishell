/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decompress_environment.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 16:27:42 by joapedr2          #+#    #+#             */
/*   Updated: 2023/05/06 17:30:13 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"



char	*decompress_environment(char *input, int size)
{
	char	*new;
	int		init;
	char	*str;
	char	*aux;

	new = input;
	if (input[0] == '~')
		return(check_tilde(input));
	while (ft_strnstr(new, "$", size))
	{
		init = ft_istrchr(new, '$');
		str = (new + init + 1);
		aux = get_env(g_data.envp, str);
		new = ft_substr(new, 0, init);
		new = ft_strjoin_free(new, aux);
		while (*str && ft_isalnum(*str))
			str++;
		if (str)
			new = ft_strjoin_free(new, str);
	}
	return (new);
}

int decompress_envp(char **cmd)
{
	int		index;

	index = -1;
	while (cmd[++index] != NULL)
		cmd[index] = decompress_environment(cmd[index], ft_strlen(cmd[index]));
	return (TRUE);
}
