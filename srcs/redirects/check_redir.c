/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 16:18:32 by feralves          #+#    #+#             */
/*   Updated: 2023/05/24 12:24:25 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	error_printing(char *input, int i)
{
	ft_putstr_fd("minishell: syntax error near ", STDERR_FILENO);
	ft_putstr_fd("unexpected token `", STDERR_FILENO);
	ft_putchar_fd(input[i], STDERR_FILENO);
	ft_putstr_fd("'\n", STDERR_FILENO);
}

int	valid_input(char c)
{
	if (is_whitespace(c))
		return (FALSE);
	if (is_redirect(c))
		return (FALSE);
	return (TRUE);
}

int	check_redirect(char *cmd_line)
{
	int	i;

	i = 0;
	while (cmd_line[i])
	{
		if (is_redirect(cmd_line[i]))
			return (TRUE);
		i++;
	}
	return (FALSE);
}

int	check_redir_syntax(char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (input[i] == '>' || input[i] == '<')
		{
			if (input[i] == input[i + 1])
				i++;
			i++;
			while (input[i] == ' ')
				i++;
			if (is_invalid(input[i]))
			{
				error_printing(input, i);
				return (0);
			}
			while (valid_input(input[i]))
				i++;
		}
		if (input[i] != '\0')
			i++;
	}
	return (i);
}

int	check_str(char **str)
{
	int	size;
	int	index;
	int	redir;

	size = 0;
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
	if (redir >= index)
		return (0);
	size = index - redir;
	return (size);
}
