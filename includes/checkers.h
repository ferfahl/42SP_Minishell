/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedr2 < joapedr2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 00:35:07 by joapedr2          #+#    #+#             */
/*   Updated: 2023/05/16 11:53:05 by joapedr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# include "minishell.h"
# include "commands.h"

// checker.c
int run_all_checks(void);

// checker_input.c
char	*check_pipe_end(char *input);
int		is_empty(char *input);
int		check_quotes(char *argument);

// checker_redir.c
int		check_redir(char *input);

// checker_symbols.c
int		is_whitespace(char c);
int		is_redirect(char c);
int		is_invalid(char c);
int		is_pipe(char c);

#endif //INPUT_H