/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedr2 < joapedr2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 12:28:52 by joapedr2          #+#    #+#             */
/*   Updated: 2023/05/02 02:40:16 by joapedr2         ###   ########.fr       */
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
int	validate_input(char *input)
{
	char	*command_line;

	if (!input || ft_strlen(input) == 0)
		return (FALSE);
	else if (!is_empty(input))
		return (FALSE);
	else if (!check_quotes(input))
		return (FALSE);
	if (ft_strncmp(input, "exit", ft_strlen(input)) == 0)
		return (FALSE);
	check_redir(input);
	// command_line = check_pipe_end(input);
	command_line = compress_quotes(input);
	if (!create_cmd_list(command_line))
		return (FALSE);
	if (input != command_line)
		free(command_line);
	return (TRUE);
}
