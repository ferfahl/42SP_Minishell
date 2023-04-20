/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 10:21:15 by joapedr2          #+#    #+#             */
/*   Updated: 2023/04/19 22:33:24 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	ft_pwd(int fd_in)
{
	int		fd[2];
	char	*tml_line;
	t_envp	*aux;

	pipe(fd,)
	fd[0] = fd_in;
	aux = g_data.envp;
	while (aux && ft_strncmp(aux->name, "PWD", 3) != 0)
		aux = aux->next;
	while (write())
		return (FALSE);
	return (TRUE);
}
