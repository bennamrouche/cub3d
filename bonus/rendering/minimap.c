/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  ebennamr <ebennamr@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:48:20 by mel-aini          #+#    #+#             */
/*   Updated: 2023/07/18 13:11:11 by  ebennamr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

int	get_color(t_point p, t_data *data)
{
	double	dis;
	double	ratio;
	int		color;

	dis = sqrt(pow((T_SIZE / 2.0) - p.x, 2) + \
	pow((T_SIZE / 2.0) - p.y, 2));
	ratio = data->frame / (double) NUM_FRAMES;
	color = 255 - (255 * ratio);
	if (dis < ((T_SIZE / 3.0) * ratio))
		return (color);
	else
		return (MAP_FLOOR);
}

int	get_color_at(double x, double y, t_data *data)
{
	t_point	point;

	point = (t_point){(int)x % T_SIZE, (int)y % T_SIZE};
	x = floor(x / T_SIZE);
	y = floor(y / T_SIZE);
	if (!is_inside((t_point){x, y}, data->width, data->height))
		return (MAP_EMPTY);
	if (data->map[(int)y][(int)x] == WALL)
		return (MAP_WALL);
	if (data->map[(int)y][(int)x] == SPACE)
		return (MAP_EMPTY);
	if (data->map[(int)y][(int)x] == PORTAL)
		return (MAP_PORTAL);
	if (data->map[(int)y][(int)x] == DOOR)
		return (MAP_DOOR);
	if (data->map[(int)y][(int)x] == SPRITE)
		return (get_color(point, data));
	return (MAP_FLOOR);
}

t_point	rotate_point(int cx, int cy, float angle, t_point p)
{
	t_point	res;

	res.x = roundf(cos(angle) * (p.x - cx) - sin(angle) * (p.y - cy) + cx);
	res.y = roundf(sin(angle) * (p.x - cx) + cos(angle) * (p.y - cy) + cy);
	return (res);
}

void	put_pixel_minimap(double distance, t_point res, t_img *img, int color)
{
	if (distance > (MAP_WIDTH / 2) - 5 && distance <= (MAP_WIDTH / 2))
		my_mlx_pixel_put(img, res.x, res.y, MAP_BORDER);
	else if (distance <= (MAP_WIDTH / 2) - 5)
		my_mlx_pixel_put(img, res.x, res.y, color);
	else
		my_mlx_pixel_put(img, res.x, res.y, 0xFF000000);
}

void	draw_minimap(t_data *data)
{
	t_point			start;
	t_point			counter;
	t_point			res;
	double			dist;
	unsigned int	color;

	counter = (t_point){0, 0};
	start = (t_point){data->player.x - (MAP_WIDTH / 2), data->player.y \
	- (MAP_HEIGHT / 2)};
	while (counter.y < MAP_HEIGHT)
	{
		counter.x = 0;
		while (counter.x < MAP_WIDTH)
		{
			color = get_color_at(start.x + counter.x, start.y \
			+ counter.y, data);
			res = rotate_point(MAP_WIDTH / 2, MAP_WIDTH / 2, (1.5 * M_PI) \
				- data->rotation_angle, counter);
			dist = distance(res, (t_point){MAP_WIDTH / 2, MAP_WIDTH / 2});
			put_pixel_minimap(dist, res, &data->minimap, color);
				counter.x += 0.6;
		}
		counter.y += 0.6;
	}
	draw_player(data);
}
