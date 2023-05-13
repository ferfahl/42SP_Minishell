/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedr2 < joapedr2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 23:51:14 by joapedr2          #+#    #+#             */
/*   Updated: 2023/05/12 18:38:11 by joapedr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_array(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}

void	free_redir(void)
{
	free(g_data.redir);
}

void	free_line(void)
{
	free(g_data.input);
	ft_free_array(g_data.path);
	free_cmd();
	free_quotes();
	free_token();
}
