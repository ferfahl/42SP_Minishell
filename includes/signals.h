/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:10:00 by joapedr2          #+#    #+#             */
/*   Updated: 2023/05/18 10:54:00 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

# include "minishell.h"
# include <signal.h>

// signals/signals.c
void	signals_handler(void);
void	signal_handler_child(void);

// signals/signals_hdoc.c
void	signal_handler_heredoc(void);

#endif // SIGNALS_H