/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_quotes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedr2 < joapedr2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 02:09:02 by joapedr2          #+#    #+#             */
/*   Updated: 2023/05/02 02:42:50 by joapedr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_quotes(void)
{
	t_quotes	*aux;
	t_quotes	*temp;

	aux = g_data.quotes;
	while (aux)
	{
		temp = NULL;
		if (aux->next)
			temp = aux->next;
		free(aux->cont);
		free(aux);
		aux = temp;
	}
	g_data.quotes = NULL;
}
