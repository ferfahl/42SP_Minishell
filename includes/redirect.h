/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:32:24 by joapedr2          #+#    #+#             */
/*   Updated: 2023/05/18 11:12:09 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECT_H
# define REDIRECT_H

# include "minishell.h"

typedef struct s_commands	t_cmd;

typedef struct	s_redir
{
	char		*symbol;
	char		*key_word;
	struct s_redir	*next;
}		t_redir;

typedef struct s_redirect
{
	int				fd_in;
	int				fd_out;
	int				has_redir;
	struct s_redir	*head_redir;
}			t_redirect;

typedef struct s_hdoc
{
	char			*line;
	struct s_hdoc	*next;
}			t_hdoc;

// redirects/redirections_list.c
void	redir_list(void);
void	keep_redir(char *symbol, char *key_word);
void	start_redirection(t_redir **redirection);

// redirects/redirections.c
void	redirections_handle(t_cmd **cmd);
char	**redirections_handle_str(char **cmd);

// redirects/execute_redir.c
void	redirect_function(char *redir, char *key_word);

// redirects/check_redir.c
int		check_redirect(char *cmd_line);
int		check_redir_syntax(char *input);
int		check_str(char **str);

// redirects/here_doc.c
int		ft_here_doc(char *eof);
void	clear_here_doc(void);

// redirects/here_doc_list.c
void	start_hd(t_hdoc **list);
void	hd_add_history(char *input);
void	print_list(int fd);

#endif //REDIRECT_H