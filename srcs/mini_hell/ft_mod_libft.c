/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mod_libft.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 11:22:07 by joapedr2          #+#    #+#             */
/*   Updated: 2023/05/17 16:13:31 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*ret;

	ret = ft_strjoin_mod(s1, s2);
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
	if (ft_isdigit(string[i]) || string[i] == '+' || string[i] == '-')
	{
		if (!string[++i])
			return (0);
		while (string[++i])
		{
			if (!ft_isdigit(string[i]))
				return (0);
		}
		return (2);
	}
	else
		return (0);
}

char	*ft_strjoin_mod(const char *s1, const char *s2)
{
	size_t	i;
	char	*str;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	i = 0;
	str = malloc((ft_strlen(s2) + ft_strlen(s1) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (s1 && *s1)
		str[i++] = *s1++;
	while (s2 && *s2)
		str[i++] = *s2++;
	str[i] = '\0';
	return (str);
}
