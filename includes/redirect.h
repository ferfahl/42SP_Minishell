/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedr2 < joapedr2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:32:24 by joapedr2          #+#    #+#             */
/*   Updated: 2023/05/05 12:19:30 by joapedr2         ###   ########.fr       */
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
}	t_redirect;

//redirections.c
char	**redirections_handle(char **gross_cmd);

//checkredir.c
char	*ft_findname(char *redir);
int		valid_input(char c);
int		check_redir_syntax(char *input);

//here_doc.c
int		ft_here_doc(char *eof);

#endif //REDIRECT_H