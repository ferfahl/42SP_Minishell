/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedr2 < joapedr2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:36:53 by joapedr2          #+#    #+#             */
/*   Updated: 2023/04/07 17:30:21 by joapedr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MESSAGES_H
# define ERROR_MESSAGES_H

# include "minishell.h"

# define ERR_ARG			"Argument error. Try: ./minishell"
# define ERR_UNEXPECTED		"Unexpected error"

# define ERR_PATH_NFOUND	"MINISHELL: envp PATH not found"
# define ERR_PWD_NFOUND		"MINISHELL: envp PWD not found"
# define ERR_PATH_ALLOC		"MINISHELL: Erro ao alocar memória path"
# define ERR_HOSTNAME_ALLOC	"MINISHELL: Erro ao alocar memória hostname"
# define ERR_PWD_ALLOC		"MINISHELL: Erro ao alocar memória pwd"

# define ERR_CMD_ALLOC		"COMMAND: Erro ao alocar memória"
# define ERR_FORK			"COMMAND: Erro na função fork"

# define ERR_ENVP_ALLOC		"ENVIRONMENT: Erro ao alocar memória"

#endif //ERROR_MESSAGES_H
