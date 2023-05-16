/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 16:17:50 by feralves          #+#    #+#             */
/*   Updated: 2023/05/16 19:48:26 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	signal_handler_hd(int child_pid)
{
	struct sigaction	sa_sigint;
	struct sigaction	sa_sigquit;

	sa_sigint.sa_flags = 0;
	sigemptyset(&sa_sigint.sa_mask);
	if (child_pid == 0)
		sa_sigint.sa_handler = SIG_DFL;
	else
		sa_sigint.sa_handler = SIG_IGN;
	sigaction(SIGINT, &sa_sigint, NULL);
	sa_sigquit.sa_flags = 0;
	sigemptyset(&sa_sigquit.sa_mask);
	sa_sigquit.sa_handler = SIG_IGN;
	sigaction(SIGQUIT, &sa_sigquit, NULL);
}

void	start_hd(t_hdoc **list)
{
	(*list) = malloc(sizeof(t_hdoc));
	(*list)->line = NULL;
	(*list)->next = NULL;
}

void	hd_add_history(t_hdoc **list, char *input)
{
	t_hdoc	*aux;
	t_hdoc	*temp;

	aux = (*list);
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


void	print_list(t_hdoc *list, int fd)
{
	t_hdoc	*tmp;

	tmp = list;
	while (tmp != NULL)
	{
		if (tmp->line)
			ft_putendl_fd(tmp->line, fd);
		tmp = tmp->next;
	}
}

void	free_list(t_hdoc **list)
{
	t_hdoc	*aux;

	while (*list)
	{
		aux = *list;
		(*list) = (*list)->next;
		free(aux->line);
		free(aux);
	}
	free(*list);
}

int	ft_here_doc(char *eof)
{
	// ft_printf("here_doc\n");
	// (void)eof;
	// return(1);
	char	*input;
	int		pid;
	t_hdoc	*list;
	int		fd[2];

	input = NULL;
	pipe(fd);
	pid = fork();
	start_hd(&list);
	signal_handler_hd(pid);
	if (pid == -1)
		terminate(ERR_FORK);
	if (pid == 0)
	{
		signal_handler_hd(pid);
		while (1)
		{
			input = readline("> ");
			if (input == NULL || !ft_strncmp(input, eof, ft_strlen(eof) + 1))
			{
				free(input);
				close(fd[0]);
				print_list(list, fd[1]);
				free_list(&list);
				close(fd[1]);
				exit(0);
			}
			if (*input)
				hd_add_history(&list, input);
			free(input);
		}
	}
	waitpid(pid, NULL, 0);
	close(fd[1]);
	return (fd[0]);
}
