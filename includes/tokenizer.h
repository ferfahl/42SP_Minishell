/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedr2 < joapedr2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:00:36 by joapedr2          #+#    #+#             */
/*   Updated: 2023/05/17 15:27:19 by joapedr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H

# include "minishell.h"

typedef enum e_token
{
	INVALID,
	WORD,
	PIPE,
	REDIRECT,
	APPEND,
	HEREDOC
}	t_etoken;

typedef struct s_tokenizer
{
	char				*cont;
	t_etoken			token;
	struct s_tokenizer	*next;
}	t_token;

// lexical_analyzer.c
int		lexical_analyzer(void);

// tokens_list.c
void	make_tokens_list(void);
void	free_token(void);

// syntax_analysis.c
int		syntax_analysis(const t_token *tokens);

#endif //TOKENIZER_H