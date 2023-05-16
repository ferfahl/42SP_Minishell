/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:46:40 by feralves          #+#    #+#             */
/*   Updated: 2023/05/16 17:06:29 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	recursive_redirections(t_redir *redirect)
{
	t_redir	*aux;

	aux = redirect;
	while (aux)
	{
		redirect_function(aux->symbol, aux->key_word);
		aux = aux->next;
	}
}

void	start_redirection(t_redir **redirection)
{
	(*redirection) = malloc(sizeof(t_redir));
	(*redirection)->symbol = NULL;
	(*redirection)->key_word = NULL;
	(*redirection)->next = NULL;
}

void	keep_redir(t_redir **redirection, char *symbol, char *key_word)
{
	t_redir	*aux;
	t_redir	*temp;

	aux = (*redirection);
	if (aux->symbol == NULL)
	{
		aux->symbol = ft_strdup(symbol);
		aux->key_word = ft_strdup(key_word);
		return ;
	}
	start_redirection(&temp);
	while (aux->next)
		aux = aux->next;
	temp->symbol = ft_strdup(symbol);
	temp->key_word = ft_strdup(key_word);
	aux->next = temp;
}

char	**redirections_handle_str(char **cmd)
{
	char	**aux;
	int		i;
	int		j;
	int		size;
	t_redir	*redirection;

	i = 0;
	j = 0;
	size = check_str(cmd);
	aux = malloc(sizeof(char *) * (size + 1));
	start_redirection(&redirection);
	while (cmd && cmd[i])
	{
		if (cmd[i] && check_redirect(cmd[i]))
		{
			keep_redir(&redirection, cmd[i], cmd[i + 1]);
			i += 2;
		}
		else
		{
			aux[j++] =  ft_strdup(cmd[i]);
			i++;
		}
		if (cmd[i] == NULL)
			break ;
	}
	aux[j] = NULL;
	// while (j >= 0)
	// {
	// 	printf("%s\n", aux[j]);
	// 	j--;
	// }
	
	recursive_redirections(redirection);
	// ft_free_array(cmd);
	return (aux);
}

void	redirections_handle(t_cmd **cmd)
{
	char	**aux;
	int		i;
	int		j;
	int		size;

	i = 0;
	j = 0;
	size = check_str((*cmd)->cmd);
	aux = malloc(sizeof(char *) * (size + 1));
	while ((*cmd)->cmd && (*cmd)->cmd[i])
	{
		if (check_redirect((*cmd)->cmd[i]))
		{
			// keep_redir((*cmd)->cmd[i], (*cmd)->cmd[i + 1]);
			j += 2;
		}
		if (!(*cmd)->cmd[i + j])
			break ;
		if (!check_redirect((*cmd)->cmd[i]))
			aux[i] =  ft_strdup((*cmd)->cmd[i + j]);
		i++;
	}
	aux[i] = NULL;
	ft_free_array((*cmd)->cmd);
	free((*cmd)->path);
	(*cmd)->path = NULL;
	(*cmd)->path = cmd_path(aux[0]);
	(*cmd)->cmd = aux;
}
