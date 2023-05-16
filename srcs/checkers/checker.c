/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedr2 < joapedr2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 11:50:25 by joapedr2          #+#    #+#             */
/*   Updated: 2023/05/16 11:55:14 by joapedr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checkers.h"

int	run_all_checks(void)
{
	if (!check_redir(g_data.input))
		return (FALSE);
	compress_quotes();
	if (!create_cmd_list(g_data.input))
		return (FALSE);
	return (TRUE);
}
