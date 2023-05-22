/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 10:56:04 by feralves          #+#    #+#             */
/*   Updated: 2023/05/22 14:59:29 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	start_redirection(t_redir **re_direct)
{
	(*re_direct) = malloc(sizeof(t_redir));
	(*re_direct)->symbol = NULL;
	(*re_direct)->key_word = NULL;
	(*re_direct)->next = NULL;
}

void	keep_redir(t_redir *re_direct, char *symbol, char *key_word)
{
	t_redir	*aux;
	t_redir	*temp;

	aux = re_direct;
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

void	redir_list(t_redir *re_direct)
{
	t_redir	*aux;

	if (!re_direct)
		return ;
	aux = re_direct;
	while (aux)
	{
		redirect_function(aux);
		if (aux->next == NULL)
			break ;
		aux = aux->next;
	}
	free_redirects(&re_direct);
}

int	check_if_redir(char **str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		if (check_redirect(str[index]))
		{
			return (TRUE);
		}
		index++;
	}
	return (FALSE);
}
