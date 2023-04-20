/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checkers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 00:18:18 by joapedr2          #+#    #+#             */
/*   Updated: 2023/04/19 22:30:42 by feralves         ###   ########.fr       */
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
