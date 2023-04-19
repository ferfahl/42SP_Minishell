/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedr2 < joapedr2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 10:21:15 by joapedr2          #+#    #+#             */
/*   Updated: 2023/03/24 10:55:03 by joapedr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	ft_pwd(int fd_in)
{
	int		fd[2];
	char	*tml_line;

	pipe(fd,)
	fd[0] = fd_in;
	t_envp	*aux;
	aux = g_data.envp;
	while (aux && ft_strncmp(aux->name, "PWD", 3) != 0)
		aux = aux->next;
	while (write())
	
	return (TRUE);	
}
