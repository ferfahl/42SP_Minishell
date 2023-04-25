/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 00:35:07 by joapedr2          #+#    #+#             */
/*   Updated: 2023/04/25 02:08:32 by joapedr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# include "minishell.h"
# include "commands.h"

typedef struct s_quotes
{
	int				pos;
	char			*cont;
	struct s_quotes	*next;
}	t_quotes;

//input_checkers.c
char	*check_pipe_end(char *input);
int		is_empty(char *input);
int		check_quotes(char *argument);

//validate_input.c
int		validate_input(char *input);

#endif //INPUT_H