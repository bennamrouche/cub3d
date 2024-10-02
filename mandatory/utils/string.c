/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 17:58:46 by ebennamr          #+#    #+#             */
/*   Updated: 2023/07/11 15:41:49 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	dp_size(char **pt)
{
	int	i;

	i = 0;
	if (pt == NULL)
		return (-1);
	while (pt[i] != NULL)
		i++;
	return (i);
}

int	char_count(char *str, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	if (str == NULL)
		return (count);
	while (str[i] != '\0')
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

int	isempty(char *line)
{
	int	i;
	int	num;

	num = 0;
	i = 0;
	if (line[0] == '\0')
		return (1);
	while (line[i])
	{
		if (ft_strchr(MAP_CHAR, line[i]) == NULL)
			error(ERR_INV_MAP);
		if (line[i] != ' ')
			num++;
		i++;
	}
	return (num);
}

void	free_dp(char **pt)
{
	int	i;

	i = 0;
	while (pt[i] != NULL)
	{
		free(pt[i]);
		i++;
	}
	free(pt);
}
