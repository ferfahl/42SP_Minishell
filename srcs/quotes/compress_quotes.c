/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress_quotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedr2 < joapedr2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 09:21:51 by joapedr2          #+#    #+#             */
/*   Updated: 2023/05/05 11:52:41 by joapedr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	new_node_quotes(char *str, int end, char c)
{
	t_quotes	*new;
	t_quotes	*last;

	new = (t_quotes *)malloc(sizeof(t_quotes));
	new->cont = ft_substr(str, 1, end);
	if (!new || !new->cont)
		terminate(ERR_QUOTES_ALLOC);
	new->envp = FALSE;
	if (c == '\"')
		new->envp = TRUE;
	new->pos = 1;
	new->next = NULL;
	if (g_data.quotes)
	{
		last = g_data.quotes;
		while (last->next != NULL)
			last = last->next;
		new->pos += last->pos;
		last->next = new;
	}
	else
		g_data.quotes = new;
	return (new->pos);
}

static char	*add_quote_identifier(char *input, int init, int end, char *nb)
{
	char	*aux;
	char	*identifier;
	char	*sub_end;

	aux = ft_substr(input, 0, init);
	sub_end = ft_substr(input, end + 1, ft_strlen(input));
	identifier = ft_strjoin("@(", nb);
	identifier = ft_strjoin_free(identifier, ")");
	aux = ft_strjoin_free(aux, identifier);
	aux = ft_strjoin_free(aux, sub_end);
	if (!aux || !sub_end || !identifier)
		terminate(ERR_QUOTES_ALLOC);
	free(nb);
	free(sub_end);
	free(identifier);
	return (aux);
}

	// t_quotes *aux = g_data.quotes;
	// while (aux)
	// {
	// 	printf("[%d][%s]\n", aux->pos, aux->cont);
	// 	aux = aux->next;
	// }
	// exit(0);
// echo 'teste "$USER $USER" $USER' hi

// static char	*compress_(char *input, char c)
// {
// 	char	*new;
// 	int		index;
// 	int		init;
// 	int		end;

// 	init = ft_istrchr(input, c);
// 	end = ft_istrchr(input + init + 1, c);
// 	index = new_node_quotes((input + init), end, TRUE);
// 	new = add_quote_identifier(input, init, end + init + 1, ft_itoa(index));
// 	return (new);
// }

void	compress_quotes(void)
{
	char	*aux;
	int		index;
	int		init;
	int		end;
	char	c;

	aux = g_data.input;
	while (ft_strchr(aux, '\"') || ft_strchr(aux, '\''))
	{
		init = ft_istrchr(aux, '\'');
		end = ft_istrchr(aux, '\"');
		if (init && (init < end || !end))
			c = '\'';
		else
			c = '\"';
		init = ft_istrchr(aux, c);
		end = ft_istrchr(aux + init + 1, c);
		index = new_node_quotes((aux + init), end, c);
		aux = add_quote_identifier(aux, init, end + init + 1, ft_itoa(index));
		free(g_data.input);
		g_data.input = aux;
	}
}
//echo $USER "$USER" '$USER' '$USER' '$USER'
