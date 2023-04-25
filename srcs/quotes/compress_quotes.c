/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress_quotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedr2 < joapedr2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 09:21:51 by joapedr2          #+#    #+#             */
/*   Updated: 2023/04/25 14:26:19 by joapedr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	new_node_quotes(char *str, int end)
{
	t_quotes	*new;
	t_quotes	*last;

	new = (t_quotes *)malloc(sizeof(t_quotes));
	if (!new)
		terminate(ERR_QUOTES_ALLOC);
	new->cont = ft_substr(str, 1, end);
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

static char	*compress_single_quote(char *input)
{
	char	*new;
	int		index;
	int		init;
	int		end;

	init = ft_istrchr(input, '\'');
	end = ft_istrchr(input + init + 1, '\'');
	index = new_node_quotes((input + init), end);
	new = add_quote_identifier(input, init, end + init + 1, ft_itoa(index));
	return (new);
}

	// t_quotes *aux = g_data.quotes;
	// while (aux)
	// {
	// 	printf("[%d][%s]\n", aux->pos, aux->cont);
	// 	aux = aux->next;
	// }
	// exit(0);
// echo 'teste "$USER $USER" $USER' hi

static char	*compress_double_quotes(char *input)
{
	char	*new;
	char	*temp;
	int		index;
	int		init;
	int		end;

	init = ft_istrchr(input, '\"');
	end = ft_istrchr(input + init + 1, '\"');
	temp = descompress_environment(input + init, end + 1);
	new = ft_substr(input, 0, init);
	init = ft_istrchr(temp, '\"');
	end = ft_istrchr(temp + init + 1, '\"');
	index = new_node_quotes((temp + init), (end - init));
	temp = add_quote_identifier(temp, init, end + 1, ft_itoa(index));
	new = ft_strjoin_free(new, temp);
	free(temp);
	return (new);
}

char	*compress_quotes(char *input)
{
	char	*new;
	int		simple;
	int		duoble;

	new = input;
	while (ft_strchr(new, '\"') || ft_strchr(new, '\''))
	{
		simple = ft_istrchr(new, '\'');
		duoble = ft_istrchr(new, '\"');
		if (simple < duoble)
			new = compress_single_quote(new);
		else
			new = compress_double_quotes(new);
	}
	return (new);
}
