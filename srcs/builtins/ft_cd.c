/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 19:23:49 by feralves          #+#    #+#             */
/*   Updated: 2023/05/06 20:59:12 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_cd_error(char *input, char *msg)
{
	ft_putstr_fd("minishell: cd: ", 1);
	if (input)
	{
		ft_putstr_fd(input, 1);
		ft_putstr_fd(": ", 1);
	}
	ft_putstr_fd(msg, 1);
	ft_putstr_fd("\n", 1);
}

char	*get_env(t_envp *env, char *key)
{
	t_envp	*temp;

	temp = env;
	while (temp)
	{
		if (!ft_strncmp(temp->name, key, ft_strlen(key) + 1))
			return (temp->cont);
		temp = temp->next;
	}
	return (NULL);
}

void	update_pwd(char *oldpwd)
{
	char	*pwd;
	t_envp	*temp;

	temp = g_data.envp;
	pwd = getcwd(NULL, 0);
	while (temp->next)
	{
		if (!ft_strncmp(temp->name, "PWD", 4))
		{
			free(temp->cont);
			temp->cont = ft_strdup(pwd);
			free(pwd);
		}
		if (!ft_strncmp(temp->name, "OLDPWD", 7))
		{
			free(temp->cont);
			temp->cont = ft_strdup(oldpwd);
		}
		temp = temp->next;
	}
}

void	ft_cd(char **input)
{
	if (!input[1])
		chdir(get_env(g_data.envp, "HOME"));
	if (input[1] && input[2])
		ft_cd_error(NULL, "too many arguments");
	if (input[1] && chdir(input[1]))
		ft_cd_error(input[1], "No such file or directory");
	update_pwd(get_env(g_data.envp, "PWD"));
}
