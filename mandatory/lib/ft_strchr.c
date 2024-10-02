/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 09:40:51 by ebennamr          #+#    #+#             */
/*   Updated: 2022/10/27 10:17:02 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int x)
{
	while (*s)
	{
		if (*s == (char)x)
			return ((char *)s);
		s++;
	}
	if (x == '\0')
		return ((char *)s);
	return (0);
}
