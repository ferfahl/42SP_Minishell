/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 12:28:52 by joapedr2          #+#    #+#             */
/*   Updated: 2023/05/04 16:54:53 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"



int	check_redir(char *input)
{
	int	i;
	int	redir_size;

	i = 0;
	g_data.redir->has_redir = FALSE;
	while (input[i])
	{
		if (is_redirect(input[i]))
		{
			g_data.redir->has_redir = TRUE;
			redir_size = check_redir_syntax(input + i);
			if (redir_size == 0)
				return (FALSE);
			i += redir_size;
		}
		i++;
	}
	return (TRUE);
}

/**
*@brief Checks input (for errors)
*@param input the input sent after the prompt
*@return False if no errors, True if errors.
*/
int	validate_input(void)
{
	if (!g_data.input || ft_strlen(g_data.input) == 0)
		return (FALSE);
	else if (!is_empty(g_data.input))
		return (FALSE);
	else if (!check_quotes(g_data.input))
		return (FALSE);
	if (ft_strncmp(g_data.input, "exit", ft_strlen(g_data.input)) == 0)
		terminate(0);
	if (!check_redir(g_data.input))
		return (FALSE);
	g_data.input = check_pipe_end(g_data.input);
	g_data.input = compress_quotes(g_data.input);
	if (!create_cmd_list(g_data.input))
		return (FALSE);
	return (TRUE);
}
