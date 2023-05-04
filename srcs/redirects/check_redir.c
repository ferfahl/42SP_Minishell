/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 16:18:32 by feralves          #+#    #+#             */
/*   Updated: 2023/05/04 16:55:00 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	error_printing(char *input, int i)
{
	ft_putstr_fd("minishell: syntax error near unexpected token `", 2);
	ft_putchar_fd(input[i], 2);
	ft_putstr_fd("'\n", 2);
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
		i++;
	}
	return (i);
}

int	valid_input(char c)
{
	if (is_whitespace(c))
		return (FALSE);
	if (is_redirect(c))
		return (FALSE);
	return (TRUE);
}

char	*ft_findname(char *redir)
{
	int		size;
	char	*name;

	size = 0;
	if (redir[size] == redir[size + 1])
		size++;
	size++;
	name = ft_strtrim(ft_strdup(redir + size), " ");
	return (name);
}
