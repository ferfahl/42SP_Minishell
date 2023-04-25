/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedr2 < joapedr2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 12:28:52 by joapedr2          #+#    #+#             */
/*   Updated: 2023/04/21 09:48:04 by joapedr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

int	validate_input(char *input)
{
	char	*command_line;

	if (ft_strncmp(input, "exit", ft_strlen(input)) == 0)
		return (FALSE);
	command_line = check_pipe_end(input);
	command_line = compress_quotes(command_line);
	if (!create_cmd_list(command_line))
		return (FALSE);
	if (input != command_line)
		free(command_line);
	return (TRUE);
}

	// command_line = pre_processador(command_line); verifica aspas e $ para 
	//comprimir e substituir o input
	//
	// Colocar a analise sintática
	// Colocar um verificador de redirecionamento