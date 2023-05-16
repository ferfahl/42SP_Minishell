/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:32:11 by joapedr2          #+#    #+#             */
/*   Updated: 2023/05/16 15:18:06 by feralves         ###   ########.fr       */
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
	char				*path;
	struct s_commands	*next;
}	t_cmd;

// commands/commands_list.c
int		create_cmd_list(char *input);
char	*cmd_path(char *command);

// commands/free_commands.c
void	free_cmd(void);

// execute/commands_list.c
int		run_command(void);

//execute/commands_builtins.c
int		execute_builtin(char **input, int check);
int		is_builtin(char *input);

#endif //COMMANDS_H