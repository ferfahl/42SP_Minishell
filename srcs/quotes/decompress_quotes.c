/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decompress_quotes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedr2 < joapedr2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 02:05:58 by joapedr2          #+#    #+#             */
/*   Updated: 2023/05/23 09:02:53 by joapedr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_compression(const char *str)
{
	char	*aux;

	aux = ft_strchr(str, '@');
	if (aux && *(aux + 1) == '(')
	{
		while (aux && *aux != ')')
			aux++;
	}
	if (!aux)
		return (FALSE);
	return (TRUE);
}

static char	*insert_compressed_txt(char *cmd, char *insert)
{
	char		*new;
	char		*after;
	int			init;
	int			size;

	new = cmd;
	init = ft_istrchr(new, '@');
	size = ft_istrchr(new + init, ')') + 1;
	ft_bzero(new + init, size);
	after = ft_strdup(new + init + size);
	new = ft_strjoin_free(new, insert);
	new = ft_strjoin_free(new, after);
	free(after);
	return (new);
}

static int	decompress_envp_quotes(char **cmd)
{
	int		control;

	if (*cmd[0] == '~')
		check_tilde(cmd);
	control = ft_istrchr(*cmd, '$');
	while (ft_strnstr(*cmd + control, "$", ft_strlen(*cmd)))
		control = decompress_envp(cmd, control);
	return (TRUE);
}

static void	decompress_quotes_cmd(char **cmd)
{
	t_quotes	*quots;
	int			index;
	int			init;

	index = -1;
	while (cmd[++index])
	{	
		while (check_compression(cmd[index]))
		{
			init = ft_istrchr(cmd[index], '@');
			quots = g_data.quotes;
			while (quots)
			{
				if (ft_atoi(cmd[index] + init + 2) == quots->pos)
				{
					if (quots->envp)
						decompress_envp_quotes(&quots->cont);
					cmd[index] = insert_compressed_txt(cmd[index], quots->cont);
					break ;
				}
				quots = quots->next;
			}
		}
	}
}

void	decompress_quotes(void)
{
	t_cmd	*aux;

	aux = g_data.cmd;
	while (aux)
	{
		decompress_quotes_cmd(aux->cmd);
		aux = aux->next;
	}
}
