/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:46:40 by feralves          #+#    #+#             */
/*   Updated: 2023/05/18 18:46:53 by feralves         ###   ########.fr       */
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

void	redirections_handle(t_cmd **cmd, t_redir **redir)
{
	char	**aux;
	int		i;
	int		j;
	int		size;

	i = 0;
	j = 0;
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
	// redir_list();
}
