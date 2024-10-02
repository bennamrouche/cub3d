/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:20:58 by ebennamr          #+#    #+#             */
/*   Updated: 2022/10/21 15:25:58 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(char *s1, const char *s2, size_t n)
{
	unsigned char	*pt1;
	unsigned char	*pt2;
	size_t			i;

	if (n == 0)
		return (0);
	pt1 = (unsigned char *)s1;
	pt2 = (unsigned char *)s2;
	i = 0;
	while (pt1[i] && pt2[i] && pt1[i] == pt2[i] && i < n -1)
	{
		i++;
	}
	return (pt1[i] - pt2[i]);
}

int	ft_strcmp( char *str1, char *str2)
{
	size_t			i;
	unsigned char	*s1x;
	unsigned char	*s2x;

	if (str1 == NULL || str2 == NULL)
		return (-1);
	s1x = (unsigned char *)str1;
	s2x = (unsigned char *)str2;
	i = 0;
	while (s1x[i] != '\0' && s2x[i] != '\0')
	{
		if (s1x[i] != s2x[i])
			return (s1x[i] - s2x[i]);
		i++;
	}
	return (s1x[i] - s2x[i]);
}
