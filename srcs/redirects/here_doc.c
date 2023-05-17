/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 16:17:50 by feralves          #+#    #+#             */
/*   Updated: 2023/05/17 15:35:56 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	clear_here_doc(void)
{
	free(g_data.input);
	ft_free_array(g_data.path);
	free_redirects(&g_data.redir->head_redir);
	free_cmd();
	free_quotes();
	free_token();
	free_list_hd();
	free_envp();
	free_redir();
	free(g_data.tml_host);
	rl_clear_history();
	exit(0);
}

static void	signint_doc(int sig)
{
	if (sig == SIGINT)
	{
		dprintf(2, "\n");
		// rl_on_new_line();
		clear_here_doc();
	}
}

void	signal_handler_heredoc(void)
{
	signal(SIGINT, signint_doc);
	signal(SIGQUIT, SIG_IGN);
}

void	start_hd(t_hdoc **list)
{
	(*list) = malloc(sizeof(t_hdoc));
	(*list)->line = NULL;
	(*list)->next = NULL;
}

void	hd_add_history(char *input)
{
	t_hdoc	*aux;
	t_hdoc	*temp;

	aux = g_data.hdoc;
	if (aux->line == NULL)
	{
		aux->line = ft_strdup(input);
		return ;
	}
	start_hd(&temp);
	while (aux->next)
		aux = aux->next;
	temp->line = ft_strdup(input);
	aux->next = temp;
}


void	print_list(int fd)
{
	t_hdoc	*tmp;

	tmp = g_data.hdoc;
	while (tmp != NULL)
	{
		if (tmp->line)
			ft_putendl_fd(tmp->line, fd);
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
	int		fd[2];

	input = NULL;
	pipe(fd);
	pid = fork();
	start_hd(&g_data.hdoc);
	signal_handler_child();
	if (pid == -1)
		terminate(ERR_FORK);
	if (pid == 0)
	{
		signal_handler_heredoc();
		while (1)
		{
			input = readline("> ");
			if (input == NULL || !ft_strncmp(input, eof, ft_strlen(eof) + 1))
			{
				free(input);
				close(fd[0]);
				print_list(fd[1]);
				close(fd[1]);
				clear_here_doc();
			}
			if (*input)
				hd_add_history(input);
			free(input);
		}
	}
	waitpid(pid, NULL, 0);
	signals_handler();
	free_list_hd();
	close(fd[1]);
	return (fd[0]);
}
