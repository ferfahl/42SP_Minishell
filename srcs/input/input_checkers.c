/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checkers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 00:18:18 by joapedr2          #+#    #+#             */
/*   Updated: 2023/05/01 14:22:34 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

static int	check_pipe(char *input)
{
	char	*str;

	str = ft_strrchr(input, '|');
	if (str && str++)
	{
		while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
			str++;
		if (*str == '\0')
			return (TRUE);
	}
	return (FALSE);
}

char	*check_pipe_end(char *input)
{
	char	*ret;
	char	*temp;
	char	*new_input;

	ret = input;
	while (check_pipe(ret))
	{
		new_input = readline("> ");
		if (new_input == NULL)
		{
			exit_terminal();
			exit(1);
		}
		if (*new_input)
		{
			add_history(new_input);
			temp = ret;
			ret = ft_strjoin(temp, new_input);
			if (temp != input)
				free(temp);
		}
		free(new_input);
	}
	return (ret);
}

/**
*@brief Checks the string for quotes
*@param argument the string to be checked
*@return -1 if not closed, 0 if closed.
*/
int	check_quotes(char *argument)
{
	int		index;
	char	quote;

	index = 0;
	while (argument[index])
	{
		if (argument[index] == '\'' || argument[index] == '\"')
		{
			quote = argument[index++];
			while (argument[index] && argument[index] != quote)
				index++;
			if (argument[index] != quote)
			{
				ft_putendl_fd("minishell: error: Unmatched quotes.", 2);
				return (FALSE);
			}
		}
		index++;
	}
	return (TRUE);
}

/**
*@brief Checks input is empty
*@param input the input sent after the prompt
*@return -1 if only spaces, 0 if others.
*/
int	is_empty(char *input)
{
	int	index;
	int	space;

	index = 0;
	space = 0;
	while (input[index] != '\0')
	{
		if (is_whitespace(input[index]))
			space++;
		index++;
	}
	if (space == index)
		return (FALSE);
	return (TRUE);
}
