/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:32:24 by joapedr2          #+#    #+#             */
/*   Updated: 2023/05/22 14:52:39 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECT_H
# define REDIRECT_H

# include "minishell.h"

typedef struct s_commands	t_cmd;

typedef struct s_redir
{
	int				fd[2];
	char			*symbol;
	char			*key_word;
	struct s_redir	*next;
}	t_redir;

typedef struct s_redirect
{
	int				fd_in;
	int				fd_out;
	int				has_redir;
}	t_redirect;

typedef struct s_hdoc
{
	char			*line;
	struct s_hdoc	*next;
}	t_hdoc;

// redirects/redirections_list.c
void	redir_list(t_redir *redir);
void	keep_redir(t_redir *redir, char *symbol, char *key_word);
void	start_redirection(t_redir **redirection);
int		check_if_redir(char **str);

// redirects/redirections.c
void	redirections_handle(t_cmd **cmd);
char	**redirections_handle_str(char **cmd);

// redirects/execute_redir.c
void	redirect_function(t_redir *redir);

// redirects/check_redir.c
int		check_redirect(char *cmd_line);
int		check_redir_syntax(char *input);
int		check_str(char **str);

// redirects/here_doc.c
int		ft_here_doc(t_redir *redir, char *eof);
void	clear_here_doc(void);

// redirects/here_doc_list.c
void	start_hd(t_hdoc **list);
void	hd_add_history(char *input);
void	print_list(int fd);

#endif //REDIRECT_H