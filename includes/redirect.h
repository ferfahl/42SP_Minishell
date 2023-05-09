/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:32:24 by joapedr2          #+#    #+#             */
/*   Updated: 2023/05/09 17:46:00 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECT_H
# define REDIRECT_H

# include "minishell.h"

typedef struct s_redirect
{
	int	fd_in;
	int	fd_out;
	int	has_redir;
}			t_redirect;

typedef struct s_hdoc
{
	char			*line;
	struct s_hdoc	*next;
}			t_hdoc;

//redirections.c
char	**redirections_handle(char **cmd);

//check_redir.c
char	*ft_findname(char *redir);
int		valid_input(char c);
int		check_redir_syntax(char *input);
int		check_redirect(char *cmd_line);

//here_doc.c
int		ft_here_doc(char *eof);

#endif //REDIRECT_H