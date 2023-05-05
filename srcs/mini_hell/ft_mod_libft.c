/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 11:22:07 by joapedr2          #+#    #+#             */
/*   Updated: 2023/05/05 12:48:23 by feralves         ###   ########.fr       */
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
	s1 = NULL;
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

long int	ft_atoi_mod(char *nptr)
{
	long int	count;
	long int	result;
	long int	signal;

	signal = 1;
	count = 0;
	result = 0;
	while ((nptr[count] >= 9 && nptr[count] <= 13) || nptr[count] == ' ')
		count++;
	if (nptr[count] == '+' || nptr[count] == '-')
	{
		if (nptr[count] == '-')
			signal = -1;
		count++;
	}
	while (count < (int)ft_strlen(nptr) && ft_isdigit(nptr[count]))
	{
		result = result * 10 + (nptr[count] - 48);
		count++;
	}
	return (result * signal);
}

int	ft_isdigit_mod(char *string)
{
	int	i;

	i = 0;
	while (string[++i])
	{
		if (!ft_isdigit(string[i]) && string[0] != '-' && string[0] != '+')
			return (0);
	}
	return (2);
}
