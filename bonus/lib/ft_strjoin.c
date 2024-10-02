/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:41:07 by ebennamr          #+#    #+#             */
/*   Updated: 2022/10/21 20:45:13 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *string1, char const *string2)
{
	int				len;
	int				count;
	char			*pt;

	if (!string1 || !string2)
		return (0);
	len = ft_strlen(string1) + ft_strlen(string2);
	count = 0;
	pt = malloc(len + 1);
	if (!pt)
		return (0);
	while (string1[count])
	{
		*(pt++) = string1[count];
		count++;
	}
	count = 0;
	while (string2[count])
	{
		*(pt++) = string2[count];
		count++;
	}
	*pt = '\0';
	return (pt - len);
}
