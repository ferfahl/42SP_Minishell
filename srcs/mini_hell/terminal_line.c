/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:34:26 by joapedr2          #+#    #+#             */
/*   Updated: 2023/05/17 16:13:45 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*tml_get_pwd(void)
{
	char	*tml_line;
	char	*e_pwd;

	tml_line = NULL;
	e_pwd = getcwd(NULL, 0);
	tml_line = ft_strjoin_mod(g_data.tml_host, e_pwd);
	free(e_pwd);
	tml_line = ft_strjoin_free(tml_line, "$ ");
	if (!tml_line)
		terminate(ERR_PWD_ALLOC);
	return (tml_line);
}

static char	*get_hostname(void)
{
	int		fd;
	char	*hostname;

	fd = open("/etc/hostname", O_RDONLY, 0644);
	if (fd == -1)
		terminate("info_create: open() failed");
	hostname = get_next_line(fd);
	hostname[ft_strlen(hostname) - 1] = '\0';
	close(fd);
	return (hostname);
}

char	*tml_user_and_host(void)
{
	char	*tml_host;
	char	*hostname;
	char	*user;
	t_envp	*aux;

	hostname = get_hostname();
	aux = g_data.envp;
	while (aux && ft_strncmp(aux->name, "USER", 4) != 0)
		aux = aux->next;
	if (!aux)
		user = "UNKNOWN";
	else
		user = aux->cont;
	tml_host = ft_strjoin_free(ft_strdup(COLOR_GREEN), user);
	tml_host = ft_strjoin_free(tml_host, "@");
	tml_host = ft_strjoin_free(tml_host, hostname);
	tml_host = ft_strjoin_free(tml_host, COLOR_RESET);
	free(hostname);
	return (tml_host);
}
