/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  ebennamr <ebennamr@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:46:32 by mel-aini          #+#    #+#             */
/*   Updated: 2023/07/18 14:31:04 by  ebennamr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

int	wall_at3(double x, double y, t_data *data)
{
	t_point	pos;

	pos = (t_point){x / T_SIZE, y / T_SIZE};
	if (!is_inside(pos, data->width, data->height))
		return (1);
	if (data->map[(int)pos.y][(int)pos.x] == WALL
		|| data->map[(int)pos.y][(int)pos.x] == DOOR
		|| data->map[(int)pos.y][(int)pos.x] == PORTAL)
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
	if (data->map[(int)new_pos.y][(int)new_pos.x] == WALL
		|| data->map[(int)new_pos.y][(int)new_pos.x] == DOOR
		|| data->map[(int)new_pos.y][(int)new_pos.x] == PORTAL)
		return (1);
	return (0);
}

void	fix_angle(double *angle)
{
	if (*angle > 2 * M_PI)
		*angle = *angle - (2 * M_PI);
	if (*angle < 0)
		*angle = (2 * M_PI) + *angle;
}

void	update_player(t_data *data)
{
	t_point	p_pos;
	double	angle;

	data->rotation_angle += data->turn_direction * (M_PI / 180) * 2;
	fix_angle(&data->rotation_angle);
	if (data->walk_direction == 2 || data->walk_direction == -2)
	{
		angle = data->rotation_angle + M_PI / data->walk_direction;
		p_pos.x = cos(angle) * 2;
		p_pos.y = sin(angle) * 2;
	}
	else
	{
		p_pos.x = cos(data->rotation_angle) * (data->walk_direction * 2);
		p_pos.y = sin(data->rotation_angle) * (data->walk_direction * 2);
	}
	if (data->walk_direction == 1 && data->wall_distance < 2.5)
		return ;
	if (!wall_at(p_pos.x, p_pos.y, data))
	{
		data->player.x += p_pos.x;
		data->player.y += p_pos.y;
	}
}

int	render(t_data *data)
{
	mlx_clear_window(data->mlx, data->win);
	draw_minimap(data);
	update_player(data);
	if (data->portal_num > 0)
	{
		portal_transition(data);
		get_portal_img(data);
	}
	cast_rays(data);
	if (data->sprite_num > 0)
	{
		get_sprite_img(data);
		render_sprites(data);
	}
	mlx_put_image_to_window(data->mlx, data->win, data->view.img, 0, 0);
	mlx_put_image_to_window(data->mlx, data->win, data->minimap.img, \
	GAP, SCREEN_HEIGHT - MAP_HEIGHT - GAP);
	data->frame++;
	if (data->frame >= NUM_FRAMES)
		data->frame = 0;
	return (0);
}
