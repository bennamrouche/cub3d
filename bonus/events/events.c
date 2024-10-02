/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:28:00 by mel-aini          #+#    #+#             */
/*   Updated: 2023/07/15 09:15:44 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"

int	key_hook(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	if (keycode == KEY_W)
		data->walk_direction = 1;
	else if (keycode == KEY_S)
		data->walk_direction = -1;
	else if (keycode == KEY_LEFT)
		data->turn_direction = -1;
	else if (keycode == KEY_RIGHT)
		data->turn_direction = 1;
	else if (keycode == KEY_A)
		data->walk_direction = -2;
	else if (keycode == KEY_D)
		data->walk_direction = 2;
	return (0);
}

int	destroy_win(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
	return (0);
}

int	key_release(int keycode, t_data *data)
{
	if (keycode == KEY_S || keycode == KEY_W
		|| keycode == KEY_A || keycode == KEY_D)
	{
		data->walk_direction = 0;
	}
	if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
	{
		data->turn_direction = 0;
	}
	return (0);
}

int	on_mouse_move(int x, int y, void *param)
{
	double	res;
	t_data	*data;
	double	res_angle;

	(void)y;
	data = (t_data *)param;
	res = x - data->last_mouse_x;
	res_angle = (2 * M_PI) * (res / SCREEN_WIDTH);
	data->rotation_angle += res_angle;
	data->last_mouse_x = x;
	return (0);
}
