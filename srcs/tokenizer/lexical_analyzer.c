/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexical_analyzer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedr2 < joapedr2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:03:20 by joapedr2          #+#    #+#             */
/*   Updated: 2023/05/12 18:37:18 by joapedr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

int	lexical_analyzer(void)
{
	t_token	*aux;

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

	compress_quotes();
	if (!create_cmd_list(g_data.input))
		return (FALSE);

	return (TRUE);
}

// t_token	*aux = tokens;
// while (aux)
// {
// 	printf("tok[%s][%d]\n", aux->cont, aux->token);
// 	aux = aux->next;
// }
