/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:49:46 by mel-aini          #+#    #+#             */
/*   Updated: 2023/07/17 14:53:22 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, unsigned int color)
{
	char	*dst;

	if (!is_inside((t_point){x, y}, data->width, data->height))
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_rectangle(t_data *data, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < T_SIZE)
	{
		j = 0;
		while (j < T_SIZE)
		{
			my_mlx_pixel_put(&data->minimap, x * T_SIZE + i, \
			y * T_SIZE + j, color);
			j++;
		}
		i++;
	}
}

void	draw_circle(t_data *data, double R, int color)
{
	t_point	p2;

	data->alpha = 0;
	while (data->alpha <= 2 * M_PI)
	{
		p2.x = MAP_CENTER + R * cos(data->alpha);
		p2.y = MAP_CENTER + R * sin(data->alpha);
		draw_line(data, p2, color, data->alpha);
		data->alpha += 0.01;
	}
}

void	draw_line(t_data *data, t_point p2, int color, double ang)
{
	int		i;
	double	dist_ab;
	double	correct_distance;

	dist_ab = distance(p2, (t_point){MAP_CENTER, MAP_CENTER});
	correct_distance = dist_ab * cos(ang);
	i = 0;
	while (i < dist_ab)
	{
		p2.x = floor(MAP_CENTER + i * cos(ang));
		p2.y = floor(MAP_CENTER + i * sin(ang));
		my_mlx_pixel_put(&data->minimap, p2.x, p2.y, color);
		i++;
	}
}

void	draw_floor_and_ceil(t_data *data, t_point p1, t_point p2, int color)
{
	int		i;

	i = p1.y;
	while (i <= p2.y)
	{
		my_mlx_pixel_put(&data->view, p1.x, i, color);
		i++;
	}
}
