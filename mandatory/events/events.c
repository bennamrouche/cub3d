/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:28:00 by mel-aini          #+#    #+#             */
/*   Updated: 2023/07/11 12:27:58 by ebennamr         ###   ########.fr       */
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
