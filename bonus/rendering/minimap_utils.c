/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 09:16:58 by mel-aini          #+#    #+#             */
/*   Updated: 2023/07/15 09:33:19 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

void	draw_player(t_data *data)
{
	t_point			end;

	end.x = MAP_CENTER + 12 * cos(data->rotation_angle);
	end.y = MAP_CENTER + 12 * sin(data->rotation_angle);
	draw_line(data, end, 0xff00ff, 1.5 * M_PI);
	draw_circle(data, 5, PLAYER_COLOR);
}
