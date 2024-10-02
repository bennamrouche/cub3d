/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_content.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 10:39:37 by mel-aini          #+#    #+#             */
/*   Updated: 2023/07/15 14:32:57 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	valid_char(t_pdata *pdata, char c)
{
	int	i;

	i = 0;
	while (pdata->allowed_chars[i])
	{
		if (c == pdata->allowed_chars[i])
			return (1);
		i++;
	}
	return (0);
}

int	is_empty(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != SPACE)
			return (0);
		i++;
	}
	return (1);
}

int	is_player(t_data *data, char dir, double x, double y)
{
	char	elem;

	elem = dir;
	if (elem == 'N' || elem == 'S' || elem == 'W' || elem == 'E')
	{
		data->player.x = x * T_SIZE + (T_SIZE / 2);
		data->player.y = y * T_SIZE + (T_SIZE / 2);
		if (elem == 'N')
			data->rotation_angle = 1.5 * M_PI;
		else if (elem == 'S')
			data->rotation_angle = 0.5 * M_PI;
		else if (elem == 'W')
			data->rotation_angle = M_PI;
		else if (elem == 'E')
			data->rotation_angle = 2 * M_PI;
		return (1);
	}
	return (0);
}

void	check_elems(t_data *data, t_pdata *pdata, int y, int *player)
{
	char	**map;
	int		x;

	map = data->map;
	x = 0;
	while (map[y][x])
	{
		if (!valid_char(pdata, map[y][x]))
			error("Invalid char");
		if (map[y][x] != WALL && map[y][x] != SPACE)
		{
			if (is_player(data, map[y][x], x, y))
				(*player)++;
			check_around(pdata, map, x, y);
		}
		if (map[y][x] == PORTAL)
			data->portal_num++;
		if (map[y][x] == SPRITE)
			data->sprite_num++;
		x++;
	}
}

char	**parse_map_content(t_data *data, t_pdata *pdata, char **map)
{
	char	**new_map;
	int		y;
	int		player;

	player = 0;
	data->portal_num = 0;
	new_map = NULL;
	pdata->end_y = get_end_y(map);
	data->height = pdata->end_y + 1;
	data->sprite_num = 0;
	pdata->allowed_chars = " 10NSWEPGD";
	y = 0;
	while (map[y])
	{
		pdata->start_x = get_start_x(map[y]);
		pdata->end_x = get_end_x(map[y], pdata->start_x);
		if (is_empty(map[y]) && y < pdata->end_y)
			error("Empty line");
		check_elems(data, pdata, y, &player);
		y++;
	}
	if (player != 1)
		error("Invalid player number");
	return (map);
}
