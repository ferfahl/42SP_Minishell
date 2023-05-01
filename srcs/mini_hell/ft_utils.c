/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedr2 < joapedr2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 11:22:07 by joapedr2          #+#    #+#             */
/*   Updated: 2023/05/01 14:10:10 by joapedr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*ret;

	ret = ft_strjoin(s1, s2);
	if (!ret)
		terminate("ft_strjoin(): Failed");
	free(s1);
	return (ret);
}

int	ft_istrchr(const char *str, char c)
{
	int		i;
	char	*find;

	i = 0;
	find = ft_strchr(str, c);
	if (!find)
		return (FALSE);
	while ((str + i) && (str + i) != find)
		i++;
	return (i);
}
