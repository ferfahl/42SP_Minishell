/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 19:24:34 by feralves          #+#    #+#             */
/*   Updated: 2023/05/23 22:18:37 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_next(char *input)
{
	int	i;

	i = 1;
	while (input[i] == 'n')
		i++;
	if (input[i] == '\0')
		return (FALSE);
	return (TRUE);
}

//with -n
void	ft_echo(char **input)
{
	int	i;
	int	new_line;

	i = 0;
	new_line = TRUE;
	if (input[i++])
	{
		if (!ft_strncmp(input[i], "-n", 2))
		{
			new_line = check_next(input[i]);
			if (!new_line)
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
