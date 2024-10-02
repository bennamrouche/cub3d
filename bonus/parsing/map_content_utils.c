/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_content_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 13:01:23 by mel-aini          #+#    #+#             */
/*   Updated: 2023/07/15 13:09:12 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	get_end_y(char **map)
{
	int	i;
	int	end_y;

	i = 0;
	end_y = 0;
	while (map[i])
	{
		if (!is_empty(map[i]))
			end_y = i;
		i++;
	}
	return (end_y);
}

int	get_start_x(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] == SPACE)
		i++;
	return (i);
}

int	get_end_x(char *line, int start_x)
{
	int	i;
	int	end_x;

	i = 0;
	end_x = 0;
	while (line[i + start_x])
	{
		if (line[i] != SPACE)
			end_x = start_x + i;
		i++;
	}
	return (end_x);
}

int	check_four_direction(char **map, int x, int y, int elem)
{
	if (map[y - 1][x] == elem || map[y + 1][x] == elem
		|| map[y][x - 1] == elem || map[y][x + 1] == elem)
	{
		return (0);
	}
	return (1);
}

void	check_around(t_pdata *pdata, char **map, int x, int y)
{
	if (y == 0 || x == pdata->start_x || y == pdata->end_y || x == pdata->end_x)
		error(ERR_INV_MAP);
	if (!check_four_direction(map, x, y, SPACE))
		error(ERR_INV_MAP);
}
