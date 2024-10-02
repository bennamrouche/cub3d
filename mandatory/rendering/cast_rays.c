/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:20:28 by mel-aini          #+#    #+#             */
/*   Updated: 2023/07/17 15:17:48 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

t_point	find_horizontal_intrsct(t_data *data, double r_angle)
{
	t_point	intersect;
	t_point	step;
	int		i;

	intersect.y = floor(data->player.y / T_SIZE) * T_SIZE;
	intersect.y += d_ternary(is_facing(r_angle, F_DOWN), T_SIZE, 0);
	intersect.x = data->player.x
		+ ((intersect.y - data->player.y) / tan(r_angle));
	step.x = T_SIZE / tan(data->cast.ray_ang);
	step.x *= d_ternary(step.x > 0 && is_facing(r_angle, F_LEFT), -1, 1);
	step.x *= d_ternary(step.x < 0 && is_facing(r_angle, F_RIGHT), -1, 1);
	step.y = T_SIZE;
	step.y *= d_ternary(is_facing(r_angle, F_UP), -1, 1);
	i = d_ternary(is_facing(r_angle, F_UP), -1, 0);
	while (is_inside(intersect, data->width * T_SIZE, data->height * T_SIZE))
	{
		if (wall_at3(intersect.x, intersect.y + i, data))
		{
			data->cast.hit_hor_wall = 1;
			break ;
		}
		intersect = (t_point){intersect.x + step.x, intersect.y + step.y};
	}
	return (intersect);
}

t_point	find_vertical_intrsct(t_data *data, double r_angle)
{
	t_point	intersect;
	t_point	step;
	int		i;

	intersect.x = floor(data->player.x / T_SIZE) * T_SIZE;
	intersect.x += d_ternary(is_facing(r_angle, F_RIGHT), T_SIZE, 0);
	intersect.y = data->player.y
		+ ((intersect.x - data->player.x) * tan(r_angle));
	step.y = T_SIZE * tan(r_angle);
	step.y *= d_ternary(step.y > 0 && is_facing(r_angle, F_UP), -1, 1);
	step.y *= d_ternary(step.y < 0 && is_facing(r_angle, F_DOWN), -1, 1);
	step.x = d_ternary(is_facing(r_angle, F_LEFT), -T_SIZE, T_SIZE);
	i = i_ternary(is_facing(r_angle, F_LEFT), -1, 0);
	while (is_inside(intersect, data->width * T_SIZE, data->height * T_SIZE))
	{
		if (wall_at3(intersect.x + i, intersect.y, data))
		{
			data->cast.hit_ver_wall = 1;
			break ;
		}
		intersect.x += step.x;
		intersect.y += step.y;
	}
	return (intersect);
}

void	find_clst_intrsct(t_data *data)
{
	double	distance_h;
	double	distance_v;

	distance_h = distance(data->cast.intersect_h, data->player);
	distance_v = distance(data->cast.intersect_v, data->player);
	distance_v = d_ternary(!data->cast.hit_ver_wall, INT_MAX, distance_v);
	distance_h = d_ternary(!data->cast.hit_hor_wall, INT_MAX, distance_h);
	if (distance_h > distance_v)
	{
		data->cast.is_ver = 1;
		data->cast.clst_intrsct = data->cast.intersect_v;
	}
	else
	{
			data->cast.is_horz = 1;
			data->cast.clst_intrsct = data->cast.intersect_h;
	}
}

void	cast_each_ray(t_data *data, int view_x)
{
	double	r_angle;

	r_angle = data->cast.ray_ang;
	data->cast.hit_hor_wall = 0;
	data->cast.hit_ver_wall = 0;
	data->cast.is_horz = 0;
	data->cast.is_ver = 0;
	fix_angle(&data->cast.ray_ang);
	data->cast.intersect_h = find_horizontal_intrsct(data, r_angle);
	data->cast.intersect_v = find_vertical_intrsct(data, r_angle);
	find_clst_intrsct(data);
	if (view_x == SCREEN_WIDTH / 2)
		data->wall_distance = distance(data->player, data->cast.clst_intrsct);
	render_walls(data, data->cast.clst_intrsct.x,
		data->cast.clst_intrsct.y, view_x);
}

void	cast_rays(t_data *data)
{
	int	i;

	i = 0;
	data->cast.ray_ang = data->rotation_angle - FOV / 2;
	while (i < NUM_RAYS)
	{
		cast_each_ray(data, i);
		data->cast.ray_ang += FOV / NUM_RAYS;
		i++;
	}
}
