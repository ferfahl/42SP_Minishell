/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 02:28:44 by joapedr2          #+#    #+#             */
/*   Updated: 2023/05/16 15:17:50 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

char	*cmd_path(char *command)
{
	char	*path;
	char	*temp;
	int		i;

	i = -1;
	while (g_data.path[++i] != NULL)
	{
		temp = ft_strjoin(g_data.path[i], "/");
		if (!temp)
			terminate(ERR_CMD_ALLOC);
		path = ft_strjoin_free(temp, command);
		if (!path || access(path, X_OK) == 0)
			break ;
		free(path);
		path = NULL;
	}
	return (path);
}

static int	new_node_cmd(char **cmd, t_cmd *cur)
{
	t_cmd	*new;

	new = (t_cmd *)malloc(sizeof(t_cmd));
	if (!new)
		terminate(ERR_CMD_ALLOC);
	new->cmd = cmd;
	new->path = cmd_path(*cmd);
	new->next = NULL;
	if (cur)
		new->next = cur;
	g_data.cmd = new;
	return (TRUE);
}

int	create_cmd_list(char *input)
{
	char	**gross_cmd;
	char	**clean_cmd;
	int		i;

	i = -1;
	gross_cmd = ft_split(input, '|');
	if (!gross_cmd)
		terminate(ERR_CMD_ALLOC);
	while (gross_cmd[++i])
	{
		clean_cmd = ft_split(gross_cmd[i], ' ');
		if (!clean_cmd)
			terminate(ERR_CMD_ALLOC);
		if (!new_node_cmd(clean_cmd, g_data.cmd))
		{
			free_cmd();
			ft_free_array(clean_cmd);
			break ;
		}
	}
	ft_free_array(gross_cmd);
	if (!g_data.cmd)
		return (FALSE);
	return (TRUE);
}
