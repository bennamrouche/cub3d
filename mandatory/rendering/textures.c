/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 13:28:43 by mel-aini          #+#    #+#             */
/*   Updated: 2023/07/17 14:51:38 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

static void	render_texture_line(t_data *data,
	t_img	*correct_wall, int index_x, int view_x)
{
	int		index_y;
	double	start_y;
	char	*dst;
	int		distance_from_top;
	t_point	count;

	start_y = (SCREEN_HEIGHT / 2) - (data->cast.wall_height / 2);
	if (start_y < 0)
		start_y = 0;
	count = (t_point){0, start_y};
	while (count.x < data->cast.wall_height && count.x < SCREEN_HEIGHT)
	{
		distance_from_top = count.y
			+ (data->cast.wall_height / 2) - (SCREEN_HEIGHT / 2);
		index_y = distance_from_top
			* (correct_wall->height / data->cast.wall_height);
		dst = correct_wall->addr + (index_y * correct_wall->line_length
				+ index_x * (correct_wall->bits_per_pixel / 8));
		my_mlx_pixel_put(&data->view, view_x, start_y
			+ count.x, *(unsigned int *)dst);
		count.y++;
		count.x++;
	}
}

void	render_textures(t_data *data, int view_x)
{
	int		start_x;
	t_img	*correct_wall;

	correct_wall = NULL;
	if (data->cast.is_ver)
	{
		if (is_facing(data->cast.ray_ang, F_LEFT))
			correct_wall = &data->wall_west;
		else
			correct_wall = &data->wall_east;
		start_x = fmod(data->cast.clst_intrsct.y, T_SIZE)
			* correct_wall->width / T_SIZE;
	}
	else
	{
		if (is_facing(data->cast.ray_ang, F_UP))
			correct_wall = &data->wall_north;
		else
			correct_wall = &data->wall_south;
		start_x = fmod(data->cast.clst_intrsct.x, T_SIZE)
			* correct_wall->width / T_SIZE;
	}
	render_texture_line(data, correct_wall, start_x, view_x);
}

static void	render_floor_and_ceil(t_data *data, int view_x)
{
	t_point	ceil_top;
	t_point	ceil_bottom;
	t_point	floor_top;
	t_point	floor_bottom;

	ceil_top.x = view_x;
	ceil_top.y = 0;
	ceil_bottom.x = view_x;
	ceil_bottom.y = data->cast.wall_top;
	floor_top.x = view_x;
	floor_top.y = data->cast.wall_top + data->cast.wall_height;
	floor_bottom.x = view_x;
	floor_bottom.y = SCREEN_HEIGHT - 1;
	if (ceil_bottom.y >= 0)
		draw_floor_and_ceil(data, ceil_top, ceil_bottom, data->c_color);
	if (floor_top.y < floor_bottom.y)
		draw_floor_and_ceil(data, floor_top, floor_bottom, data->f_color);
}

void	render_walls(t_data *data, double x, double y, int view_x)
{
	double	dis_to_wall;
	double	dis_to_projection_plan;
	double	correct_dis;

	dis_to_projection_plan = (SCREEN_WIDTH / 2) / tan(FOV / 2);
	dis_to_wall = distance(data->player, (t_point){x, y});
	correct_dis = dis_to_wall
		* cos(data->rotation_angle - data->cast.ray_ang);
	data->cast.wall_height = (T_SIZE / correct_dis) * dis_to_projection_plan;
	data->cast.wall_top = (SCREEN_HEIGHT / 2) - (data->cast.wall_height / 2);
	if (data->cast.wall_top < 0)
		data->cast.wall_top = 0;
	data->cast.wall_bottom = data->cast.wall_top + data->cast.wall_height;
	if (data->cast.wall_bottom >= SCREEN_HEIGHT)
		data->cast.wall_bottom = SCREEN_HEIGHT - 1;
	render_textures(data, view_x);
	if (data->cast.wall_bottom < SCREEN_HEIGHT - 1)
		render_floor_and_ceil(data, view_x);
}
