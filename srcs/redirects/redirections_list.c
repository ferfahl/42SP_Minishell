/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 10:56:04 by feralves          #+#    #+#             */
/*   Updated: 2023/05/18 10:57:07 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	start_redirection(t_redir **redirection)
{
	(*redirection) = malloc(sizeof(t_redir));
	(*redirection)->symbol = NULL;
	(*redirection)->key_word = NULL;
	(*redirection)->next = NULL;
}

void	keep_redir(char *symbol, char *key_word)
{
	t_redir	*aux;
	t_redir	*temp;

	aux = g_data.redir->head_redir;
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

void	redir_list(void)
{
	t_redir	*aux;

	aux = g_data.redir->head_redir;
	while (aux)
	{
		redirect_function(aux->symbol, aux->key_word);
		if (aux->next == NULL)
			break ;
		aux = aux->next;
	}
	free_redirects(&g_data.redir->head_redir);
}
