/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:32:24 by joapedr2          #+#    #+#             */
/*   Updated: 2023/05/16 16:19:36 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECT_H
# define REDIRECT_H

# include "minishell.h"

typedef struct s_commands	t_cmd;

typedef struct s_redirect
{
	int	fd_in;
	int	fd_out;
	int	has_redir;
}			t_redirect;

typedef struct	s_redir
{
	char		*symbol;
	char		*key_word;
	struct s_redir	*next;
}		t_redir;

typedef struct s_hdoc
{
	char			*line;
	struct s_hdoc	*next;
}			t_hdoc;

//redirections.c
void	redirections_handle(t_cmd **cmd);

//redir_str.c
char	**redirections_handle_str(char **cmd);

//execute_redir.c
void	redirect_function(char *redir, char *key_word);

//check_redir.c
int		check_str(char **str);
int		valid_input(char c);
int		check_redir_syntax(char *input);
int		check_redirect(char *cmd_line);

//here_doc.c
int		ft_here_doc(char *eof);

#endif //REDIRECT_H