/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedr2 < joapedr2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:31:57 by joapedr2          #+#    #+#             */
/*   Updated: 2023/05/02 01:48:11 by joapedr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRONMENT_H
# define ENVIRONMENT_H

# include "minishell.h"

typedef struct s_envp
{
	char			*name;
	char			*cont;
	struct s_envp	*next;
}	t_envp;

// environment.c
int		init_envp(char **envp);
void	free_envp(void);
char	*decompress_environment(char *input, int size);
int		decompress_envp(char **cmd);

#endif //ENVIRONMENT_H
