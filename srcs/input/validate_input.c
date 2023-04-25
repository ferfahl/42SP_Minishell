/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 12:28:52 by joapedr2          #+#    #+#             */
/*   Updated: 2023/04/20 20:21:21 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

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
	// command_line = pre_processador(command_line); verifica $ para 
	//comprimir e substituir o input
	command_line = check_pipe_end(input);
	if (!create_cmd_list(command_line))
		return (FALSE);
	if (input != command_line)
		free(command_line);
	return (TRUE);
}
