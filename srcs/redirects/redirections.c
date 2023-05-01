/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:46:40 by feralves          #+#    #+#             */
/*   Updated: 2023/05/01 14:51:27 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_findname(char *redir)
{
	int	size;

	size = 0;
	if (redir[size] == redir[size + 1])
		size++;
	size++;
	while (redir[size] == ' ')
		size++;
	return (ft_strdup(redir + size));
}

void	redirect_function(char *redir)
{
	int		i;
	char	*name;

	i = 0;
	(void)i;
	ft_printf("Redirect: %s\n", redir);
	name = ft_findname(redir);
	(void)name;
	// while (redir[i])
	// {
	// 	if (redir[i] == '>')
	// 		if (redir[i++] == '>')
	// 			ft_append(redir);
	// 		else
	// 			ft_outfile(redir + i);
	// 	if (redir[i] == '<')
	// 		if (redir[i++] == '<')
	// 			ft_here_doc(redir);
	// 		else
	// 			ft_infile(redir + i)
	// }
}

static int	valid_input(char c)
{
	if (is_whitespace(c))
		return (FALSE);
	if (is_redirect(c))
		return (FALSE);
	if (c == '\0')
		return (FALSE);
	return (TRUE);
}

size_t	get_redir(char *cmd_line, char *cleaner_cmd)
{
	char	*redir;
	size_t	size;
	size_t	i;

	i = -1;
	size = 0;
	if (cmd_line[size] == cmd_line[size + 1])
		size++;
	size++;
	while (cmd_line[size] == ' ')
		size++;
	if (is_invalid(cmd_line[size]))
	{
		free(cleaner_cmd);
		exit (0); //quebra o redirect e para as funções
	}
	while (valid_input(cmd_line[size]) == TRUE)
		size++;
	redir = malloc(sizeof(char) * (size + 1));
	while (++i < size)
		redir[i] = cmd_line[i];
	redirect_function(redir);
	free(redir);
	return (size);
}

char	*remove_redir(char	*cmd_line)
{
	char	*cleaner_cmd;
	char	*after;
	int		size;
	int		redir_size;
	int		j;

	size = 0;
	j = 0;
	while (cmd_line[size] && !is_redirect(cmd_line[size]))
		size++;
	cleaner_cmd = malloc(sizeof(char) * (size + 1));
	cleaner_cmd[size] = '\0';
	while (--size >= 0)
		cleaner_cmd[size] = cmd_line[size];
	redir_size = get_redir(cmd_line + ft_strlen(cleaner_cmd), cleaner_cmd);
	size = ft_strlen(cleaner_cmd) + redir_size;
	while (cmd_line[size + j] && !is_redirect(cmd_line[size + j]))
		j++;
	if (*(cmd_line + size + j) != '\0')
		after = remove_redir(cmd_line + size);
	else
		after = ft_strdup(cmd_line + size);
	return (ft_strjoin_free(cleaner_cmd, after));
}

char	**redirections_handle(char **gross_cmd)
{
	int	i;

	i = 0;
	while (gross_cmd[i])
	{
		gross_cmd[i] = remove_redir(gross_cmd[i]);
		i++;
	}
	return (gross_cmd);
}
