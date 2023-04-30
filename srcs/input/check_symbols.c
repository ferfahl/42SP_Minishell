/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_symbols.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 11:10:26 by feralves          #+#    #+#             */
/*   Updated: 2023/04/27 18:30:18 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_invalid(char c)
{
	if (c == '&' || c == '#' || c == '(' || c == ')' || c == '*')
		return (TRUE);
	return (FALSE);
}

int	is_redirect(char c)
{
	if (c == '<' || c == '>')
		return (TRUE);
	return (FALSE);
}

int	is_quote(char c)
{
	if (c == '\'' || c == '\"')
		return (TRUE);
	return (FALSE);
}

int	is_whitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\0')
		return (TRUE);
	return (FALSE);
}

int	is_separator(char c)
{
	if (c == ';')
		return (TRUE);
	return (FALSE);
}
