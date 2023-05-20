/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_analysis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedr2 < joapedr2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:24:17 by joapedr2          #+#    #+#             */
/*   Updated: 2023/05/20 20:06:51 by joapedr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

static int	put_error_message(char *str)
{
	ft_putstr("minishell: syntax error near unexpected token ");
	ft_printf("`%s\'\n", str);
	return (FALSE);
}

int	syntax_analysis(const t_token *tokens)
{
	int	is_pipe;

	is_pipe = tokens->token == PIPE;
	if (tokens->token == WORD)
		return (TRUE);
	if (tokens->next == NULL)
		return (put_error_message("newline"));
	if (tokens->token == INVALID)
		return (put_error_message(tokens->cont));
	if (tokens->next->token == PIPE)
		return (put_error_message(tokens->next->cont));
	if (!is_pipe && tokens->next->token == REDIRECT)
		return (put_error_message(tokens->next->cont));
	if (!is_pipe && tokens->next->token == APPEND)
		return (put_error_message(tokens->next->cont));
	if (!is_pipe && tokens->next->token == HEREDOC)
		return (put_error_message(tokens->next->cont));
	return (TRUE);
}
