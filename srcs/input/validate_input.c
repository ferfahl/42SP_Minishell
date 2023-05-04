/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 12:28:52 by joapedr2          #+#    #+#             */
/*   Updated: 2023/05/04 12:04:00 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

void	check_redir(char *input)
{
	g_data.redir = FALSE;
	while (*input)
	{
		if (is_redirect(*input))
		{
			g_data.redir = TRUE;
			break ;
		}
		input++;
	}
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
		return (FALSE);
	check_redir(g_data.input);
	// g_data.input = check_pipe_end(input);
	g_data.input = compress_quotes(g_data.input);
	if (!create_cmd_list(g_data.input))
		return (FALSE);
	return (TRUE);
}
