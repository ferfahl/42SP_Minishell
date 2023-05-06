/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 19:24:34 by feralves          #+#    #+#             */
/*   Updated: 2023/05/05 21:56:26 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//with -n
void	ft_echo(char **input)
{
	int	i;
	int	new_line;

	i = 1;
	new_line = TRUE;
	if (input[i])
	{
		if (!ft_strncmp(input[i], "-n", 3))
		{
			new_line = FALSE;
			i++;
		}
		while (input[i])
		{
			ft_putstr_fd(input[i], 1);
			i++;
			if (input[i])
				ft_putstr_fd(" ", 1);
		}
	}
	if (new_line)
		ft_putstr_fd("\n", 1);
}
