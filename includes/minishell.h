/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedr2 < joapedr2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:31:20 by joapedr2          #+#    #+#             */
/*   Updated: 2023/04/25 02:08:22 by joapedr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "environment.h"
# include "signals.h"
# include "input.h"
# include "commands.h"
# include "builtins.h"
// # include "redirect.h"
# include "error_messages.h"

# include <readline/readline.h>	//readline()
# include <readline/history.h>	//readline()
# include <errno.h>				//errno
# include <stdio.h>				//perror()
# include <fcntl.h>				//open()
# include <signal.h>			//struct sigaction

typedef struct s_envp		t_envp;
typedef struct sigaction	t_sigaction;
typedef struct s_commands	t_cmd;
typedef struct s_quotes		t_quotes;

typedef struct s_minishell
{
	int			loop;
	t_cmd		*cmd;
	t_envp		*envp;
	char		**envp_cmd;
	char		**path;
	char		*tml_host;
	char		*tml_line;
	t_sigaction	sa_signal;
	t_quotes	*quotes;
	pid_t		pid;
}	t_minishell;

extern t_minishell			g_data;

// mini_hell/minishell_utils.c
void	terminate(char *s);
int		init_data(char **envp);
void	free_path(void);
void	exit_terminal(void);

// mini_hell/terminal_line.c
char	*tml_get_pwd(void);
char	*tml_user_and_host(void);

// mini_hell/free_minishell
void	ft_free_array(char **arr);

// mini_hell/ft_utils.c
char	*ft_strjoin_free(char *s1, char *s2);
int		ft_istrchr(const char *str, char c);

// quotes
char	*compress_quotes(char *input);


#endif //MINISHELL_H