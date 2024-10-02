/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 13:42:41 by ebennamr          #+#    #+#             */
/*   Updated: 2022/10/23 13:56:10 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int x, size_t n)
{
	size_t				i;

	i = 0;
	while (i < n)
	{
		*(unsigned char *)(str + i) = (unsigned char) x;
		i++;
	}
	return (str);
}
