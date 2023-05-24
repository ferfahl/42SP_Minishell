/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executables.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedr2 < joapedr2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 12:07:51 by joapedr2          #+#    #+#             */
/*   Updated: 2023/05/24 15:50:22 by joapedr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"
#include <sys/stat.h>

static int	check_executable(t_cmd *aux)
{
	char	*temp;
	int		init;
	int		end;

	if (aux->path != NULL)
		return (FALSE);
	end = ft_strlen(aux->cmd[0]);
	init = end;
	if (access(aux->cmd[0], X_OK) != 0)
		return (FALSE);
	while (*(aux->cmd[0] + init) != '/')
		init--;
	if (end != init)
	{
		aux->path = ft_strdup(aux->cmd[0]);
		temp = ft_substr(aux->cmd[0], init + 1, end);
		free (aux->cmd[0]);
		aux->cmd[0] = temp;
	}
	return (TRUE);
}

int	executables_files(void)
{
	t_cmd	*aux;

	aux = g_data.cmd;
	if (!aux->cmd[0])
		return (FALSE);
	while (aux)
	{
		if (*(aux)->cmd[0] == '.' || *(aux)->cmd[0] == '/')
			check_executable(aux);
		aux = aux->next;
	}
	return (TRUE);
}
