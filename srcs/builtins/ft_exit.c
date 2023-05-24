/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 19:26:00 by feralves          #+#    #+#             */
/*   Updated: 2023/05/24 11:58:26 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_clean_exit(int status)
{
	exit_terminal();
	exit(status);
}

static void	ft_exit_invalid(char *input, int status, int errorno)
{
	if (errorno == 1)
		ft_putstr_fd("exit: exited with too many arguments\n", STDERR_FILENO);
	else
	{
		ft_putstr_fd("exit: ", STDERR_FILENO);
		ft_putstr_fd(input, STDERR_FILENO);
		ft_putstr_fd(" exited with invalid argument\n", STDERR_FILENO);
	}
	exit_terminal();
	exit(status);
}

void	ft_exit(char **input)
{
	int	i;

	i = 1;
	if (input[1] == NULL)
		ft_clean_exit(EXIT_SUCCESS);
	else
	{
		while (input[i])
		{
			if (input[2])
				ft_exit_invalid(input[1], 42, 1);
			else if (ft_isdigit_mod(input[i]))
				ft_clean_exit(ft_atoi_mod(input[1]));
			else
				ft_exit_invalid(input[1], 2, 0);
			i++;
		}
	}
}
