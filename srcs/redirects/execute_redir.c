/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_redir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 12:12:07 by feralves          #+#    #+#             */
/*   Updated: 2023/05/19 11:25:16 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	redirect_function(char *redir, char *key_word)
{
	int		i;
	int		fd;

	i = 0;

	if (redir[i] == '>')
	{
		if (redir[i + 1] && redir[++i] == '>')
			fd = open(key_word, O_CREAT | O_WRONLY | O_APPEND, 0644);
		else
			fd = open(key_word, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		dup2(fd, STDOUT_FILENO);
	}
	if (redir[i] == '<')
	{
		if (redir[++i] == '<')
			fd = ft_here_doc(key_word);
		else
			fd = open(key_word, O_RDONLY);
		if (!fd)
			fd = open("/dev/null", O_RDONLY);
		dup2(fd, STDIN_FILENO);
	}
	close(fd);
}
