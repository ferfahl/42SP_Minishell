/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 19:23:49 by feralves          #+#    #+#             */
/*   Updated: 2023/05/24 12:11:09 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_cd_error(char *input, char *msg)
{
	g_data.exit_status = 1;
	ft_putstr_fd("minishell: cd: ", STDERR_FILENO);
	if (input)
	{
		ft_putstr_fd(input, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
	}
	ft_putendl_fd(msg, STDERR_FILENO);
}

void	update_pwd(char *oldpwd)
{
	char	*pwd;
	char	*temporary;
	t_envp	*temp;

	temp = g_data.envp;
	pwd = getcwd(NULL, 0);
	temporary = ft_strdup(oldpwd);
	while (temp)
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
			temp->cont = temporary;
		}
		if (temp->next == NULL)
			break ;
		temp = temp->next;
	}
}

static void	ft_cd_oldpwd(void)
{
	char	*oldpwd;

	g_data.exit_status = 1;
	oldpwd = get_env("OLDPWD");
	if (!oldpwd)
		ft_cd_error(NULL, "OLDPWD not set");
	else
		chdir(oldpwd);
}

void	ft_cd(char **input)
{
	char	*oldpwd;

	oldpwd = get_env("PWD");
	if (!input[1])
		chdir(get_env("HOME"));
	else if (input[1] && input[2])
		ft_cd_error(NULL, "too many arguments");
	else if (input[1] && input[1][0] == '-')
		ft_cd_oldpwd();
	else if (input[1] && chdir(input[1]))
		ft_cd_error(input[1], "No such file or directory");
	if (oldpwd)
		update_pwd(oldpwd);
}
