/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 10:26:07 by ebennamr          #+#    #+#             */
/*   Updated: 2022/10/21 10:41:52 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	getnumlen(int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n > 9)
	{
		len++;
		n = n / 10;
	}
	len++;
	return (len);
}

char	*ft_itoa(int n)
{
	char		*pt;
	int			i;

	i = getnumlen(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	pt = (char *)malloc(sizeof(char) * (i + 1));
	if (!pt)
		return (0);
	if (n < 0)
	{
		n *= -1;
		*pt = '-';
	}
	*(pt + i) = '\0';
	i--;
	while (n > 9)
	{
		*(pt + i) = (n % 10) + '0';
		i --;
		n /= 10;
	}
	*(pt + i) = n + '0';
	return (pt);
}
