/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:31:57 by joapedr2          #+#    #+#             */
/*   Updated: 2023/05/08 14:23:52 by feralves         ###   ########.fr       */
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

// environment/environment.c
int		init_envp(char **envp);
char	*get_env(char *name);

// environment/free_environment.c
void	free_envp(void);

// environment/decompress_environment.c
void	decompress_environment(char **input, int size);
int		decompress_envp(char **cmd);

// environment/decompress_tilde.c
void	check_tilde(char **input);

// environment/envp_for_execve.c
char	**ft_mini_to_envp(t_envp *mini_env);

#endif //ENVIRONMENT_H
