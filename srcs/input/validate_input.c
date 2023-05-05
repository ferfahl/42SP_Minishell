/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedr2 < joapedr2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 12:28:52 by joapedr2          #+#    #+#             */
/*   Updated: 2023/05/05 12:09:08 by joapedr2         ###   ########.fr       */
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
	if (!is_empty(g_data.input))
		return (FALSE);
	else if (!check_quotes(g_data.input))
		return (FALSE);
	if (ft_strncmp(g_data.input, "exit", ft_strlen(g_data.input)) == 0)
		terminate(0);
	if (!check_redir(g_data.input))
		return (FALSE);
	check_redir(g_data.input);
	// g_data.input = check_pipe_end(input);
	compress_quotes();
	if (!create_cmd_list(g_data.input))
		return (FALSE);
	return (TRUE);
}
