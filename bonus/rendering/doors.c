/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 11:32:01 by mel-aini          #+#    #+#             */
/*   Updated: 2023/07/15 14:32:57 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

static void	auto_close(t_data *data, t_point count)
{
	double	dist;
	t_point	helper;

	while (++count.y < data->height)
	{
		count.x = -1;
		while (++count.x < data->width)
		{
			if (data->map[(int)count.y][(int)count.x] == 'X')
			{
				helper.x = count.x * T_SIZE + T_SIZE / 2;
				helper.y = count.y * T_SIZE + T_SIZE / 2;
				dist = distance(helper, data->player);
				data->map[(int)count.y][(int)count.x] = \
				i_ternary(dist > 1.5 * T_SIZE, DOOR, 'X');
			}
		}
	}
}

void	door_auto_close_open(t_data *data, t_cast cast)
{
	t_point	helper;
	t_point	count;

	count = (t_point){-1, -1};
	if (cast.is_hit_door && data->wall_distance <= 2 * T_SIZE)
	{
		helper.y = i_ternary(cast.is_horz \
		&& is_facing(data->ray_ang, F_UP), -1, 0);
		helper.x = i_ternary(cast.is_ver \
		&& is_facing(data->ray_ang, F_LEFT), -1, 0);
		helper.x = (cast.clst_intrsct.x / T_SIZE) + helper.x;
		helper.y = cast.clst_intrsct.y / T_SIZE + helper.y;
		data->map[(int)helper.y][(int)helper.x] = 'X';
	}
	auto_close(data, count);
}
