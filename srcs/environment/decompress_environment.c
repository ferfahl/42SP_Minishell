/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decompress_environment.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedr2 < joapedr2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 16:27:42 by joapedr2          #+#    #+#             */
/*   Updated: 2023/05/02 02:05:29 by joapedr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"

char	*decompress_environment(char *input, int size)
{
	char	*new;
	int		init;
	char	*str;
	t_envp	*aux;

	new = input;
	while (ft_strnstr(new, "$", size))
	{
		init = ft_istrchr(new, '$');
		str = (new + init + 1);
		aux = g_data.envp;
		while (aux != NULL)
		{
			if (!ft_strncmp(aux->name, str, ft_strlen(aux->name)))
			{
				new = ft_substr(new, 0, init);
				new = ft_strjoin_free(new, aux->cont);
				while (*str && ft_isalnum(*str))
					str++;
				if (str)
					new = ft_strjoin_free(new, str);
				break ;
			}
			aux = aux->next;
		}
	}
	return (new);
}

// char	*decompress_environment(char *input, int size)
// {
// 	char	*new;
// 	int		init;
// 	char	*envp;
// 	t_envp	*aux;

// 	new = input;
// 	while (ft_strnstr(new, "$", size))
// 	{
// 		init = ft_istrchr(new, '$');
// 		envp = (new + init + 1);
// 		aux = g_data.envp;
// 		while (aux->next != NULL)
// 		{
// 			if (!ft_strncmp(aux->name, envp, ft_strlen(aux->name)))
// 				break ;
// 			aux = aux->next;
// 		}
// 		new = ft_substr(new, 0, init);
// 		if (aux->next != NULL)
// 			new = ft_strjoin_free(new, aux->cont);
// 		while (*envp && ft_isalnum(*envp))
// 			envp++;
// 		new = ft_strjoin_free(new, envp);
// 	}
// 	return (new);
// }

int decompress_envp(char **cmd)
{
	int		index;

	index = -1;
	while (cmd[++index] != NULL)
		cmd[index] = decompress_environment(cmd[index], ft_strlen(cmd[index]));
	return (TRUE);
}