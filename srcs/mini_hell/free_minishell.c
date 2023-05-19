/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 23:51:14 by joapedr2          #+#    #+#             */
/*   Updated: 2023/05/18 22:41:25 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_array(char **arr)
{
	int	i;

	i = -1;
	if (!arr)
		return ;
	while (arr && arr[++i])
		free(arr[i]);
	free(arr);
}

void	free_list_hd(void)
{
	t_hdoc	*aux;

	while (g_data.hdoc)
	{
		aux = g_data.hdoc;
		(g_data.hdoc) = (g_data.hdoc)->next;
		free(aux->line);
		free(aux);
	}
	free(g_data.hdoc);
}

void	free_redirects(t_redir **redirect)
{
	t_redir	*aux;

	while (*redirect)
	{
		aux = *redirect;
		(*redirect) = (*redirect)->next;
		free(aux->symbol);
		free(aux->key_word);
		free(aux);
	}
	free(*redirect);
}

void	free_redir(void)
{
	free(g_data.redir);
}

void	free_line(void)
{
	free(g_data.input);
	ft_free_array(g_data.path);
	free_cmd();
	free_quotes();
	free_token();
}
