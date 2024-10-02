/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 13:28:43 by mel-aini          #+#    #+#             */
/*   Updated: 2023/07/17 14:22:49 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

static void	put_texture_pixel(t_data *data, int i, int y, int view_x)
{
	char	*dst;
	int		distance_from_top;
	double	wall_height;

	wall_height = data->curr_ray->wall_height;
	distance_from_top = y + (wall_height / 2) - (SCREEN_HEIGHT / 2);
	data->t_index.y = distance_from_top * \
	(data->correct_wall->height / wall_height);
	dst = data->correct_wall->addr + ((int)data->t_index.y * \
	data->correct_wall->line_length \
	+ (int)data->t_index.x * (data->correct_wall->bits_per_pixel / 8));
	my_mlx_pixel_put(&data->view, view_x, data->t_start.y + i, \
	*(unsigned int *)dst);
}

void	render_texture_line(t_data *data, int view_x)
{
	int		y;
	int		i;

	data->t_start.y = (SCREEN_HEIGHT / 2) - (data->curr_ray->wall_height / 2);
	if (data->t_start.y < 0)
		data->t_start.y = 0;
	y = data->t_start.y;
	i = 0;
	while (i < data->curr_ray->wall_height && i < SCREEN_HEIGHT)
	{
		put_texture_pixel(data, i, y, view_x);
		y++;
		i++;
	}
}

t_img	*get_correct_wall(t_data *data, t_cast *ray, int dir)
{
	t_img	*img;

	if (ray->is_hit_door == 1)
		img = &data->img_door;
	else if (ray->is_hit_portal == 1)
		img = &data->portal_main_img;
	else if (dir == 1)
	{
		if (is_facing(data->ray_ang, F_LEFT))
			img = &data->wall_west;
		else
			img = &data->wall_east;
	}
	else
	{
		if (is_facing(data->ray_ang, F_UP))
			img = &data->wall_north;
		else
			img = &data->wall_south;
	}
	return (img);
}

void	render_textures(t_data *data, int view_x, t_cast *ray)
{
	data->correct_wall = NULL;
	if (ray->is_ver)
	{
		data->correct_wall = get_correct_wall(data, ray, 1);
		data->t_index.x = fmod(ray->clst_intrsct.y, T_SIZE) * \
		data->correct_wall->width / T_SIZE;
	}
	else
	{
		data->correct_wall = get_correct_wall(data, ray, 2);
		data->t_index.x = fmod(ray->clst_intrsct.x, T_SIZE) * \
		data->correct_wall->width / T_SIZE;
	}
	render_texture_line(data, view_x);
}
