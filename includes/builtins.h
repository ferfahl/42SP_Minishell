/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 10:21:38 by joapedr2          #+#    #+#             */
/*   Updated: 2023/05/05 13:44:00 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "minishell.h"

//ft_cd.c
void	ft_cd(void);

//ft_echo.c
void	ft_echo(void);

//ft_env.c
void	ft_env(void);
void	ft_env_from_export(void);

//ft_exit.c
void	ft_exit(void);

//ft_export_check.c
char	**ft_var_export(char *cmd);

//ft_export.c
void	ft_export(void);

//ft_pwd.c
void	ft_pwd(void);

//ft_unset.c
void	ft_unset(void);

#endif //BUILTINS_H