/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 19:25:27 by feralves          #+#    #+#             */
/*   Updated: 2023/04/19 19:25:46 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// int	is_varname(char c)
// {
// 	return (ft_isalnum(c) || c == '_');
// }

// int	check_valid_var(char *name)
// {
// 	if (!ft_isalpha(*name))
// 		return (FALSE);
// 	while (*name)
// 	{
// 		if (!is_varname(*name))
// 			return (FALSE);
// 		name++;
// 	}
// 	return (TRUE);
// }

// char	**ft_var_export(char *cmd)
// {
// 	char	**command;

// 	command = ft_split(cmd, '=');
// 	if (!check_valid_var(command[0]))
// 		return (NULL);
// 	if (!command[1])
// 		command[1] = ft_strdup("");
// 	return (command);
// }
