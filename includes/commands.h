/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:32:11 by joapedr2          #+#    #+#             */
/*   Updated: 2023/04/21 15:55:01 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDS_H
# define COMMANDS_H

# include "minishell.h"
# include "error_messages.h"
# include <sys/wait.h>	// waitpid

typedef struct s_commands
{
	char				**cmd;
	char				**redir;
	char				*path;
	struct s_commands	*next;
}	t_cmd;

// commands.c
int		run_command(void);
int		create_cmd_list(char *input);
int		syntax_analysis(char **command);

// commands_list.c
int		new_node_cmd(char **cmd, t_cmd *cur);
void	free_cmd(void);

#endif //COMMANDS_H