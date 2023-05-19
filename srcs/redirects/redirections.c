/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:46:40 by feralves          #+#    #+#             */
/*   Updated: 2023/05/19 00:12:32 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**redirections_handle_str(char **cmd)
{
	char	**aux;
	int		i;
	int		j;
	int		size;
	t_redir	*redir;

	i = 0;
	j = 0;
	redir = NULL;
	size = check_str(cmd);
	aux = malloc(sizeof(char *) * (size + 1));
	start_redirection(&redir);
	while (cmd && cmd[i])
	{
		if (cmd[i] && check_redirect(cmd[i]))
		{
			keep_redir(redir, cmd[i], cmd[i + 1]);
			i++;
		}
		else
			aux[j++] = ft_strdup(cmd[i]);
		if (cmd[i++] == NULL)
			break ;
	}
	aux[j] = NULL;
	redir_list(redir);
	return (aux);
}

t_cmd	*adjust_cmd(char **aux, t_cmd *cmd)
{
	ft_free_array(cmd->cmd);
	free(cmd->path);
	cmd->path = NULL;
	cmd->path = cmd_path(aux[0]);
	cmd->cmd = aux;
	return (cmd);
}

int	check_temp(char **str)
{
	int	index;
	int	redir;

	index = 0;
	redir = 0;
	while (str[index])
	{
		if (check_redirect(str[index]))
		{
			redir += 2;
		}
		index++;
	}
	return (redir);
}

void	redirections_handle(t_cmd **cmd, t_redir **redir)
{
	char	**aux;
	int		i;
	int		j;
	int		size;

	i = 0;
	j = 0;
	if (!check_temp((*cmd)->cmd))
		return ;
	size = check_str((*cmd)->cmd);
	aux = malloc(sizeof(char *) * (size + 1));
	start_redirection(redir);
	while ((*cmd)->cmd && (*cmd)->cmd[i])
	{
		if (check_redirect((*cmd)->cmd[i]))
		{
			keep_redir(*redir, (*cmd)->cmd[i], (*cmd)->cmd[i + 1]);
			i++;
		}
		else
			aux[j++] = ft_strdup((*cmd)->cmd[i]);
		if (!(*cmd)->cmd[i++])
			break ;
	}
	aux[j] = NULL;
	*cmd = adjust_cmd(aux, *cmd);
}
