/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 10:46:07 by feralves          #+#    #+#             */
/*   Updated: 2023/05/18 10:47:32 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	start_hd(t_hdoc **list)
{
	(*list) = malloc(sizeof(t_hdoc));
	(*list)->line = NULL;
	(*list)->next = NULL;
}

void	hd_add_history(char *input)
{
	t_hdoc	*aux;
	t_hdoc	*temp;

	aux = g_data.hdoc;
	if (aux->line == NULL)
	{
		aux->line = ft_strdup(input);
		return ;
	}
	start_hd(&temp);
	while (aux->next)
		aux = aux->next;
	temp->line = ft_strdup(input);
	aux->next = temp;
}

void	print_list(int fd)
{
	t_hdoc	*tmp;

	tmp = g_data.hdoc;
	while (tmp != NULL)
	{
		if (tmp->line)
			ft_putendl_fd(tmp->line, fd);
		tmp = tmp->next;
	}
}
