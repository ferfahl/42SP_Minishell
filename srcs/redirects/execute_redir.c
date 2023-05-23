/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_redir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 12:12:07 by feralves          #+#    #+#             */
/*   Updated: 2023/05/23 19:26:42 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	redirect_function(t_redir *redir)
{
	int		i;
	int		fd;

	i = 0;
	if (redir->symbol[i] == '>')
	{
		if (redir->symbol[i + 1] && redir->symbol[++i] == '>')
			fd = open(redir->key_word, O_CREAT | O_WRONLY | O_APPEND, 0644);
		else
			fd = open(redir->key_word, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		dup2(fd, STDOUT_FILENO);
	}
	if (redir->symbol[i] == '<')
	{
		if (redir->symbol[++i] == '<')
			fd = ft_here_doc(redir->key_word);
		else
			fd = open(redir->key_word, O_RDONLY);
		if (fd == -1)
		{
			ft_putstr_fd("minishell: ", 2);
			ft_putstr_fd(redir->key_word, 2);
			ft_putstr_fd(": No such file or directory\n", 2);
			return (FALSE);
		}
		dup2(fd, STDIN_FILENO);
	}
	close(fd);
	return (TRUE);
}
