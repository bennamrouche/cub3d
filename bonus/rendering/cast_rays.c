/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  ebennamr <ebennamr@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:20:28 by mel-aini          #+#    #+#             */
/*   Updated: 2023/07/18 13:11:21 by  ebennamr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

t_point	find_horizontal_intrsct(t_data *data, t_cast *ray)
{
	t_point	intrsct;
	t_point	step;
	int		i;

	intrsct.y = floor(data->player.y / T_SIZE) * T_SIZE;
	intrsct.y += d_ternary(is_facing(data->ray_ang, F_DOWN), T_SIZE, 0);
	intrsct.x = data->player.x + ((intrsct.y - data->player.y) \
	/ tan(data->ray_ang));
	step.x = T_SIZE / tan(data->ray_ang);
	step.x *= d_ternary(step.x > 0 \
	&& is_facing(data->ray_ang, F_LEFT), -1, 1);
	step.x *= d_ternary(step.x < 0 \
	&& is_facing(data->ray_ang, F_RIGHT), -1, 1);
	step.y = d_ternary(is_facing(data->ray_ang, F_UP), -T_SIZE, T_SIZE);
	i = d_ternary(is_facing(data->ray_ang, F_UP), -1, 0);
	while (is_inside(intrsct, data->width * T_SIZE, data->height * T_SIZE))
	{
		if (wall_at3(intrsct.x, intrsct.y + i, data))
		{
			ray->hit_hor_wall = 1;
			break ;
		}
		intrsct = (t_point){intrsct.x + step.x, intrsct.y + step.y};
	}
	return (intrsct);
}

t_point	find_vertical_intrsct(t_data *data, t_cast *ray)
{
	t_point	intrsct;
	t_point	step;
	int		i;

	intrsct.x = floor(data->player.x / T_SIZE) * T_SIZE;
	intrsct.x += d_ternary(is_facing(data->ray_ang, F_RIGHT), T_SIZE, 0);
	intrsct.y = data->player.y + ((intrsct.x - data->player.x) \
	* tan(data->ray_ang));
	step.y = T_SIZE * tan(data->ray_ang);
	step.y *= d_ternary(step.y > 0 && is_facing(data->ray_ang, F_UP), -1, 1);
	step.y *= d_ternary(step.y < 0 \
	&& is_facing(data->ray_ang, F_DOWN), -1, 1);
	step.x = d_ternary(is_facing(data->ray_ang, F_LEFT), \
	-T_SIZE, T_SIZE);
	i = i_ternary(is_facing(data->ray_ang, F_LEFT), -1, 0);
	while (is_inside(intrsct, data->width * T_SIZE, data->height * T_SIZE))
	{
		if (wall_at3(intrsct.x + i, intrsct.y, data))
		{
			ray->hit_ver_wall = 1;
			break ;
		}
		intrsct = (t_point){intrsct.x + step.x, intrsct.y + step.y};
	}
	return (intrsct);
}

void	find_clst_intrsct(t_data *data, t_cast *ray)
{
	double	distance_h;
	double	distance_v;

	distance_h = distance(ray->intersect_h, data->player);
	distance_v = distance(ray->intersect_v, data->player);
	distance_v = d_ternary(!ray->hit_ver_wall, INT_MAX, distance_v);
	distance_h = d_ternary(!ray->hit_hor_wall, INT_MAX, distance_h);
	if (distance_h > distance_v)
	{
		ray->is_ver = 1;
		ray->clst_intrsct = ray->intersect_v;
	}
	else
	{
		ray->is_horz = 1;
		ray->clst_intrsct = ray->intersect_h;
	}
	if (get_at(ray->clst_intrsct.x, ray->clst_intrsct.y, data, ray) == DOOR)
		ray->is_hit_door = 1;
	if (get_at(ray->clst_intrsct.x, ray->clst_intrsct.y, data, ray) == PORTAL)
		ray->is_hit_portal = 1;
}

void	cast_each_ray(t_data *data, t_cast *ray, int view_x)
{
	ray->hit_hor_wall = 0;
	ray->hit_ver_wall = 0;
	ray->is_horz = 0;
	ray->is_ver = 0;
	data->curr_ray = ray;
	fix_angle(&data->ray_ang);
	ray->intersect_h = find_horizontal_intrsct(data, ray);
	ray->intersect_v = find_vertical_intrsct(data, ray);
	find_clst_intrsct(data, ray);
	if (get_at(ray->clst_intrsct.x, ray->clst_intrsct.y, data, ray) == DOOR)
		ray->is_hit_door = 1;
	if (view_x == SCREEN_WIDTH / 2)
	{
		data->wall_distance = distance(data->player, ray->clst_intrsct);
		door_auto_close_open(data, *ray);
	}
	render_walls(data, ray->clst_intrsct.x, ray->clst_intrsct.y, view_x);
}

void	cast_rays(t_data *data)
{
	int	i;

	i = 0;
	data->ray_ang = data->rotation_angle - (FOV / 2);
	while (i < NUM_RAYS)
	{
		data->rays[i].is_hit_door = 0;
		data->rays[i].is_hit_portal = 0;
		cast_each_ray(data, &data->rays[i], i);
		data->ray_ang += FOV / NUM_RAYS;
		i++;
	}
}
