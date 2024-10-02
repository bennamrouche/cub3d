/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   portal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 11:00:03 by mel-aini          #+#    #+#             */
/*   Updated: 2023/07/17 07:58:28 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

void	get_portal_img(t_data *data)
{
	int	a;
	int	selector;

	a = NUM_FRAMES / PORTAL_IMGS;
	selector = data->frame / a;
	if (selector < PORTAL_IMGS && selector >= 0)
		data->portal_main_img = data->portal[selector];
}

int	random_num(int x, int n)
{
	int	a;
	int	c;
	int	m;

	a = 5;
	c = 8;
	m = 7;
	x = (a * x + c) % m;
	if (x == a)
		x++;
	while (x > n)
		x = (a * x + c) % m;
	return (x);
}

void	set_new_position(t_data *data, int x, int y, double angle)
{
	data->player.x = (x * T_SIZE) + (T_SIZE / 2);
	data->player.y = (y * T_SIZE) + (T_SIZE / 2);
	data->rotation_angle = angle;
}

// int	valid_portal(t_data *data, int x, int y)
// {
// 	if (data->map[y][x + 1] == FLOOR)
// 		set_new_position(data, x + 1, y, 2 * M_PI);
// 	if (data->map[y][x - 1] == FLOOR)
// 		set_new_position(data, x - 1, y, M_PI);
// 	if (data->map[y + 1][x] == FLOOR)
// 		set_new_position(data, x, y + 1, 0.5 * M_PI);
// 	if (data->map[y - 1][x] == FLOOR)
// 		set_new_position(data, x, y - 1, 1.5 * M_PI);
// 	else
// 		return (0);
// 	return (1);
// }

int	valid_portal(t_data *data, int x, int y, int *n)
{
	if (data->map[y][x] == PORTAL)
	{
		(*n)++;
		if (*n == data->rand_n)
		{
			if (data->map[y][x + 1] == FLOOR)
				set_new_position(data, x + 1, y, 2 * M_PI);
			if (data->map[y][x - 1] == FLOOR)
				set_new_position(data, x - 1, y, M_PI);
			if (data->map[y + 1][x] == FLOOR)
				set_new_position(data, x, y + 1, 0.5 * M_PI);
			if (data->map[y - 1][x] == FLOOR)
				set_new_position(data, x, y - 1, 1.5 * M_PI);
			else
				return (0);
			return (1);
		}
	}
	return (0);
}

void	portal_transition(t_data *data)
{
	int	y;
	int	x;
	int	n;

	if (data->rays[SCREEN_WIDTH / 2].is_hit_portal
		&& data->rays[SCREEN_WIDTH / 2].distance_to_wall < T_SIZE / 2)
	{
		data->rand_n = random_num((int)floor(data->player.x) \
		% data->portal_num, data->portal_num);
		n = 0;
		y = -1;
		while (data->map[++y] && n < data->portal_num)
		{
			x = -1;
			while (data->map[y][++x] && n < data->portal_num)
			{
				if (valid_portal(data, x, y, &n))
					return ;
			}
		}
	}
}
