/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:51:43 by mel-aini          #+#    #+#             */
/*   Updated: 2022/11/21 16:08:41 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	length(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	check_line(const char *s, int c)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*join(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1 && !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (length(s1) + length(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	if (s1)
	{
		while (s1[i])
		{
			str[i] = s1[i];
			i++;
		}
	}
	j = -1;
	while (s2[++j])
		str[i + j] = s2[j];
	str[i + j] = '\0';
	if (s1)
		free(s1);
	return (str);
}

char	*save(char *s, char c)
{
	char	*ret;
	int		i;
	int		len;

	if (!*s)
		return (NULL);
	len = 0;
	i = -1;
	while (s[++i])
	{
		if (s[i] == c)
		{
			len = 1;
			break ;
		}
	}
	len = len + i;
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	i = -1;
	while (++i < len)
		ret[i] = s[i];
	ret[i] = '\0';
	return (ret);
}

char	*remain(char *s, char c)
{
	char	*rem;
	int		i;
	int		j;
	int		len;

	if (!s)
		return (NULL);
	i = 0;
	if (!check_line(s, c))
		return (NULL);
	while (s[i] != c)
		i++;
	len = length(s) - i - 1;
	rem = (char *)malloc(sizeof(char) * (len + 1));
	if (!rem)
		return (NULL);
	j = 0;
	while (j < len)
	{
		rem[j] = s[++i];
		j++;
	}
	rem[j] = '\0';
	return (rem);
}
