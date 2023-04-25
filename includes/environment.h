/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedr2 < joapedr2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:31:57 by joapedr2          #+#    #+#             */
/*   Updated: 2023/04/25 01:21:26 by joapedr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRONMENT_H
# define ENVIRONMENT_H

# include "minishell.h"

# define GRN "\001\e[0;32m\002"
# define CRESET "\001\e[0m\002"

typedef struct s_envp
{
	char			*name;
	char			*cont;
	struct s_envp	*next;
}	t_envp;

// environment.c
int		init_envp(char **envp);
void	free_envp(void);
char	*descompress_environment(char *input, int size);

#endif //ENVIRONMENT_H