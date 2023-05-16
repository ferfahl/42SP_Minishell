/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedr2 < joapedr2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 12:28:52 by joapedr2          #+#    #+#             */
/*   Updated: 2023/05/16 11:41:41 by joapedr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checkers.h"

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
		if (input[i] != '\0')
			i++;
	}
	return (TRUE);
}
