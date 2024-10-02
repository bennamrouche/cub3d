/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  ebennamr <ebennamr@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:46:32 by mel-aini          #+#    #+#             */
/*   Updated: 2023/07/18 14:30:03 by  ebennamr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

int	wall_at3(double x, double y, t_data *data)
{
	t_point	pos;

	pos = (t_point){x / T_SIZE, y / T_SIZE};
	if (!is_inside(pos, data->width, data->height))
		return (1);
	if (data->map[(int)pos.y][(int)pos.x] == WALL)
		return (1);
	return (0);
}

int	wall_at(double x, double y, t_data *data)
{
	t_point	new_pos;

	new_pos.x = floor(data->player.x + x) / T_SIZE;
	new_pos.y = floor(data->player.y + y) / T_SIZE;
	if (!is_inside(new_pos, data->width, data->height))
		return (1);
	if (data->map[(int)new_pos.y][(int)new_pos.x] == WALL)
		return (1);
	return (0);
}

void	update_player(t_data *data)
{
	double	x;
	double	y;
	double	angle;

	data->rotation_angle += data->turn_direction * (M_PI / 180) * 2;
	fix_angle(&data->rotation_angle);
	if (data->walk_direction == 2 || data->walk_direction == -2)
	{
		angle = data->rotation_angle + M_PI / data->walk_direction;
		x = cos(angle) * 2;
		y = sin(angle) * 2;
	}
	else
	{
		x = cos(data->rotation_angle) * data->walk_direction * 2;
		y = sin(data->rotation_angle) * data->walk_direction * 2;
	}
	if (data->walk_direction == 1 && data->wall_distance < 2.5)
		return ;
	if (!wall_at(x, y, data))
	{
		data->player.x += x;
		data->player.y += y;
	}
}

void	initialize(t_data *data, t_pdata *pdata)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		error(ERR_OUT_OF_MEM);
	data->win = mlx_new_window(data->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3d");
	if (!data->win)
		error(ERR_OUT_OF_MEM);
	data->view.img = NULL;
	data->wall_north.img = NULL;
	data->wall_south.img = NULL;
	data->wall_west.img = NULL;
	data->wall_east.img = NULL;
	data->turn_direction = 0;
	data->walk_direction = 0;
	data->c_color = pdata->color_cl;
	data->f_color = pdata->color_flr;
	create_images(data, pdata);
}

int	render(t_data *data)
{
	mlx_clear_window(data->mlx, data->win);
	update_player(data);
	cast_rays(data);
	mlx_put_image_to_window(data->mlx, data->win, data->view.img, 0, 0);
	return (0);
}
