/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:31:57 by joapedr2          #+#    #+#             */
/*   Updated: 2023/04/19 22:35:16 by feralves         ###   ########.fr       */
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

#endif //ENVIRONMENT_H