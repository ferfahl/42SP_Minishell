/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedr2 < joapedr2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:07:20 by joapedr2          #+#    #+#             */
/*   Updated: 2023/05/17 15:17:20 by joapedr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

void	free_token(void)
{
	t_token	*aux;
	t_token	*temp;

	aux = g_data.tokens;
	while (aux)
	{
		temp = NULL;
		if (aux->next)
			temp = aux->next;
		free(aux->cont);
		free(aux);
		aux = temp;
	}
	g_data.tokens = NULL;
}

static t_etoken	define_token(char *str)
{
	if (!ft_strncmp(str, "|", 2))
		return (PIPE);
	if (!ft_strncmp(str, ">>", 3))
		return (APPEND);
	if (!ft_strncmp(str, ">", 2))
		return (REDIRECT);
	if (!ft_strncmp(str, "<<", 3))
		return (HEREDOC);
	if (!ft_strncmp(str, "<", 2))
		return (REDIRECT);
	if (is_invalid(*str))
		return (INVALID);
	return (WORD);
}

static void	new_node_tokens(char *str)
{
	t_token	*new;
	t_token	*last;

	new = (t_token *)malloc(sizeof(t_token));
	if (!new || !str)
		terminate(ERR_LEXER_ALLOC);
	new->cont = str;
	new->token = define_token(str);
	new->next = NULL;
	if (g_data.tokens)
	{
		last = g_data.tokens;
		while (last->next != NULL)
			last = last->next;
		last->next = new;
	}
	else
		g_data.tokens = new;
}

void	make_tokens_list(void)
{
	int		init;
	int		end;

	init = 0;
	while (g_data.input[init] && g_data.input[init + 1])
	{
		end = 0;
		while (is_whitespace(g_data.input[init]))
			init++;
		while (!is_whitespace(g_data.input[init + end]))
		{
			if ((is_redirect(g_data.input[init + end])
					|| is_pipe(g_data.input[init + end])
					|| is_invalid(g_data.input[init + end])))
			{
				if (!end && is_redirect(g_data.input[init + (++end)]))
					end++;
				break ;
			}
			end++;
		}
		new_node_tokens(ft_substr(g_data.input, init, end));
		init += end;
	}
}
