/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 08:36:04 by mel-aini          #+#    #+#             */
/*   Updated: 2023/07/17 14:54:27 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

char	get_at(double x, double y, t_data *data, t_cast *ray)
{
	t_point	new_pos;
	t_point	test;

	test = (t_point){0, 0};
	if (ray->is_horz)
		test.y = d_ternary(is_facing(data->ray_ang, F_UP), -1, 0);
	if (ray->is_ver)
		test.x = i_ternary(is_facing(data->ray_ang, F_LEFT), -1, 0);
	new_pos.x = x / T_SIZE;
	new_pos.y = y / T_SIZE;
	if (!is_inside(new_pos, data->width, data->height))
		return ('1');
	return (data->map[(int)(new_pos.y + test.y)][(int)(new_pos.x + test.x)]);
}

int	is_facing(double angle, int facing)
{
	if (facing == 1)
		return (angle > M_PI && angle < 2 * M_PI);
	else if (facing == 2)
		return (angle > 0 && angle < M_PI);
	else if (facing == 3)
		return (angle > 3 * M_PI / 2 || angle < M_PI / 2);
	else if (facing == 4)
		return (angle > M_PI / 2 && angle < 3 * M_PI / 2);
	else
		return (0);
}

void	render_floor_and_ceil(t_data *data, int view_x, t_cast *ray)
{
	t_point		ceil_top;
	t_point		ceil_bottom;
	t_point		floor_top;
	t_point		floor_bottom;

	ceil_top.x = view_x;
	ceil_top.y = 0;
	ceil_bottom.x = view_x;
	ceil_bottom.y = ray->wall_top;
	floor_top.x = view_x;
	floor_top.y = ray->wall_top + ray->wall_height;
	floor_bottom.x = view_x;
	floor_bottom.y = SCREEN_HEIGHT - 1;
	if (ceil_bottom.y >= 0)
		draw_floor_and_ceil(data, ceil_top, ceil_bottom, data->c_color);
	if (floor_top.y < floor_bottom.y)
		draw_floor_and_ceil(data, floor_top, floor_bottom, data->f_color);
}

void	render_walls(t_data *data, double x, double y, int view_x)
{
	double	correct_distance;

	data->curr_ray->distance_to_wall = sqrt(pow(x - data->player.x, 2) \
	+ pow(y - data->player.y, 2));
	correct_distance = data->curr_ray->distance_to_wall * \
	cos(data->rotation_angle - data->ray_ang);
	data->curr_ray->wall_height = (T_SIZE / correct_distance) * \
	data->dis_to_pp;
	data->curr_ray->wall_top = (SCREEN_HEIGHT / 2) \
	- (data->curr_ray->wall_height / 2);
	if (data->curr_ray->wall_top < 0)
		data->curr_ray->wall_top = 0;
	data->curr_ray->wall_bottom = data->curr_ray->wall_top \
	+ data->curr_ray->wall_height;
	if (data->curr_ray->wall_bottom >= SCREEN_HEIGHT)
		data->curr_ray->wall_bottom = SCREEN_HEIGHT - 1;
	render_textures(data, view_x, data->curr_ray);
	if (data->curr_ray->wall_bottom < SCREEN_HEIGHT - 1)
		render_floor_and_ceil(data, view_x, data->curr_ray);
}
