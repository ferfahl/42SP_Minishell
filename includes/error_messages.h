/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:36:53 by joapedr2          #+#    #+#             */
/*   Updated: 2023/05/21 03:42:44 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MESSAGES_H
# define ERROR_MESSAGES_H

# include "minishell.h"

# define ERR_ARG			"Argument error. Try: ./minishell"
# define ERR_UNEXPECTED		"Unexpected error"

# define ERR_PATH_NFOUND	"MINISHELL: envp PATH not found"
# define ERR_PWD_NFOUND		"MINISHELL: envp PWD not found"
# define ERR_PATH_ALLOC		"MINISHELL: error with alloc in path"
# define ERR_HOSTNAME_ALLOC	"MINISHELL: error with alloc in hostname"
# define ERR_PWD_ALLOC		"MINISHELL: error with alloc in pwd"

# define ERR_CMD_ALLOC		"COMMAND: error with alloc in"
# define ERR_FORK			"COMMAND: error with fork"

# define ERR_ENVP_ALLOC		"ENVIRONMENT: error with alloc"

# define ERR_INPUT_QUOTES	"INPUT: error while compressing quotes"
# define ERR_QUOTES_ALLOC	"INPUT: error with alloc in compressor"

# define ERR_LEXER_ALLOC	"LEXER: error with alloc"

# define ERR_SYNTAX			"SYNTAX: sintax error"

#endif //ERROR_MESSAGES_H
