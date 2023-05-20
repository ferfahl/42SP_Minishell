/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_redir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 12:12:07 by feralves          #+#    #+#             */
/*   Updated: 2023/05/19 11:45:28 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	redirect_function(t_redir *redir)
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
			fd = ft_here_doc(redir, redir->key_word);
		else
			fd = open(redir->key_word, O_RDONLY);
		if (!fd)
			fd = open("/dev/null", O_RDONLY);
		dup2(fd, STDIN_FILENO);
	}
	close(fd);
}
