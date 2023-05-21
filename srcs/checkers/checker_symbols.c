/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_symbols.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedr2 < joapedr2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 11:10:26 by feralves          #+#    #+#             */
/*   Updated: 2023/05/17 19:44:49 by joapedr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checkers.h"

int	is_invalid(char c)
{
	if (c == '&' || c == '#' || c == '(' || c == ')'
		|| c == ';' || c == '{' || c == '}')
		return (TRUE);
	if (is_redirect(c))
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

int	is_pipe(char c)
{
	if (c == '|')
		return (TRUE);
	return (FALSE);
}
