/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 16:17:50 by feralves          #+#    #+#             */
/*   Updated: 2023/05/09 18:33:12 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	handler_hd(int signal)
{
	(void)signal;
	ft_putstr_fd("\n", STDOUT_FILENO);
	rl_replace_line("", 0);
}

void	signal_handler_hd(void)
{
	signal(SIGINT, &handler_hd);
	signal(SIGQUIT, SIG_IGN);
}

t_hdoc	*add_node_line(char *input)
{
	t_hdoc	*new_node;

	new_node = (t_hdoc *)malloc(sizeof(t_hdoc));
	new_node->line = ft_strdup(input);
	new_node->next = NULL;
	return (new_node);
}

void	hd_add_history(t_hdoc **list, char *input)
{
	t_hdoc	*temp;

	temp = *list;
	while (temp->next)
	{
		temp = temp->next;
	}
	temp->next = add_node_line(input);
}

t_hdoc	*start_hd(void)
{
	t_hdoc	*new;

	new = malloc(sizeof(t_hdoc));
	new->line = NULL;
	new->next = NULL;
	return (new);
}

void	print_list(t_hdoc *list)
{
	t_hdoc	*tmp;

	tmp = list;
	while (tmp != NULL)
	{
		ft_printf("%s\n", tmp->line);
		tmp = tmp->next;
	}
}

int	ft_here_doc(char *eof)
{
	// ft_printf("here_doc\n");
	// (void)eof;
	// return(1);
	char	*input;
	int		pid;
	t_hdoc	*list;

	input = NULL;
	pid = fork();
	list = start_hd();
	signal_handler_hd();
	if (pid == -1)
		terminate(ERR_FORK);
	if (pid == 0)
	{
		while (1)
		{
			input = readline("> ");
			if (input == NULL || !ft_strncmp(input, eof, ft_strlen(eof) + 1))
			{
				exit(0);
			}
			if (*input)
			{
				hd_add_history(&list, input);
			}
			free(input);
		}
	}
	waitpid(pid, NULL, 0);
	print_list(list);
	// dup2(g_data.redir->fd_in, STDIN_FILENO);
	// dup2(g_data.redir->fd_out, STDOUT_FILENO);
	return (1);
}
