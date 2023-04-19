/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedr2 < joapedr2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 00:35:07 by joapedr2          #+#    #+#             */
/*   Updated: 2023/04/10 00:43:51 by joapedr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# include "minishell.h"
# include "commands.h"

//input_checkers.c
char	*check_pipe_end(char *input);

//validate_input.c
int		validate_input(char *input);

#endif //INPUT_H