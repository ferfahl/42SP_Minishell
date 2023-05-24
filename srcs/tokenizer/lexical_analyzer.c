/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexical_analyzer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedr2 < joapedr2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:03:20 by joapedr2          #+#    #+#             */
/*   Updated: 2023/05/24 11:52:08 by joapedr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

int	lexical_analyzer(void)
{
	t_token	*aux;

	compress_quotes();
	make_tokens_list();
	aux = g_data.tokens;
	if (!aux)
		return (FALSE);
	while (aux != NULL)
	{
		if (!syntax_analysis(aux))
			return (FALSE);
		aux = aux->next;
	}
	aux = g_data.tokens;
	free(g_data.input);
	g_data.input = ft_strdup("");
	while (aux)
	{
		g_data.input = ft_strjoin_free(g_data.input, " ");
		g_data.input = ft_strjoin_free(g_data.input, aux->cont);
		aux = aux->next;
	}
	return (TRUE);
}
