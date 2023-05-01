/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 16:18:32 by feralves          #+#    #+#             */
/*   Updated: 2023/05/01 16:32:43 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	valid_input(char c)
{
	if (is_whitespace(c))
		return (FALSE);
	if (is_redirect(c))
		return (FALSE);
	return (TRUE);
}

char	*ft_findname(char *redir)
{
	int		size;
	char	*name;

	size = 0;
	if (redir[size] == redir[size + 1])
		size++;
	size++;
	name = ft_strtrim(ft_strdup(redir + size), " ");
	return (name);
}
