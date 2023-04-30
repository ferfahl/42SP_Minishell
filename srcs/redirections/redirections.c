/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:46:40 by feralves          #+#    #+#             */
/*   Updated: 2023/04/27 18:39:57 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	redirect_function(char *redir)
{
	ft_printf("Redirect: %s\n", redir);
}
static int	valid_input(char c)
{
	if (is_whitespace(c))
		return (FALSE);
	else if (is_invalid(c))
		return (FALSE);
	else if (is_redirect(c))
		return (FALSE);
	return (TRUE)
}

char	*remove_redir(char	*cmd_line)
{
	char	*cleaner_cmd;
	char	*redir;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (cmd_line[i])
	{
		if (is_redirect(cmd_line[i]))
		{
			redir[j++] = cmd_line[i++];
			if (cmd_line[i - 1] == cmd_line[i] || cmd_line == ' ')
				redir[j++] = cmd_line[i++];
			if (valid_input(cmd[i]) == TRUE)
				redir[j++] = cmd_line[i++];
		}
		if (j != 0)
			redirect_function(redir);
		i++;
	}
	return (cleaner_cmd);
}

char	**redirections_handle(char **gross_cmd)
{
	char	**temp;
	int		i;

	i = 0;
	temp = gross_cmd;
	while(gross_cmd[i])
	{
		gross_cmd[i] = remove_redir(gross_cmd[i]);
		i++;
	}
}
