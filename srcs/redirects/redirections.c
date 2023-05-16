/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:46:40 by feralves          #+#    #+#             */
/*   Updated: 2023/05/16 14:07:04 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**redirections_handle_str(char **cmd)
{
	char	**aux;
	int		i;
	int		j;
	int		size;

	i = 0;
	j = 0;
	size = check_str(cmd);
	aux = malloc(sizeof(char *) * (size + 1));
	while (cmd && cmd[i])
	{
		if (check_redirect(cmd[i]))
		{
			redirect_function(cmd[i], cmd[i + 1]);
			j += 2;
		}
		if (!cmd[i + j])
			break ;
		aux[i] =  cmd[i + j];
		i++;
	}
	aux[i] = NULL;
	return (aux);
}

void	redirections_handle(t_cmd **cmd)
{
	char	**aux;
	int		i;
	int		j;
	int		size;

	i = 0;
	j = 0;
	size = check_str((*cmd)->cmd);
	aux = malloc(sizeof(char *) * (size + 1));
	while ((*cmd)->cmd && (*cmd)->cmd[i])
	{
		if (check_redirect((*cmd)->cmd[i]))
		{
			redirect_function((*cmd)->cmd[i], (*cmd)->cmd[i + 1]);
			j += 2;
		}
		if (!(*cmd)->cmd[i + j])
			break ;
		aux[i] =  ft_strdup((*cmd)->cmd[i + j]);
		i++;
	}
	aux[i] = NULL;
	ft_free_array((*cmd)->cmd);
	(*cmd)->cmd = aux;
}
