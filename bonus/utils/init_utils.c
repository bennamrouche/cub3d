/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 10:54:36 by mel-aini          #+#    #+#             */
/*   Updated: 2023/07/17 08:48:35 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	free_list(t_list *head)
{
	t_list	*tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

void	create_portal_images(t_data *data)
{
	data->portal = malloc(sizeof(t_img) * PORTAL_IMGS);
	check_ptr(data->portal, "portal imgs");
	create_mlx_image(data, &data->portal[0], "textures/portal/portal1.xpm");
	create_mlx_image(data, &data->portal[1], "textures/portal/portal2.xpm");
	create_mlx_image(data, &data->portal[2], "textures/portal/portal3.xpm");
	create_mlx_image(data, &data->portal[3], "textures/portal/portal4.xpm");
	create_mlx_image(data, &data->portal[4], "textures/portal/portal5.xpm");
	create_mlx_image(data, &data->portal[5], "textures/portal/portal6.xpm");
	create_mlx_image(data, &data->portal[6], "textures/portal/portal7.xpm");
	create_mlx_image(data, &data->portal[7], "textures/portal/portal8.xpm");
	create_mlx_image(data, &data->portal[8], "textures/portal/portal9.xpm");
	create_mlx_image(data, &data->portal[9], "textures/portal/portal10.xpm");
	data->portal_main_img = data->portal[0];
}

void	create_sprite_images(t_data *data)
{
	data->sprite = malloc(sizeof(t_img) * SPRITE_IMGS);
	check_ptr(data->sprite, "sprite imgs");
	create_mlx_image(data, &data->sprite[0], "textures/sprites/ghost1.xpm");
	create_mlx_image(data, &data->sprite[1], "textures/sprites/ghost2.xpm");
	create_mlx_image(data, &data->sprite[2], "textures/sprites/ghost3.xpm");
	create_mlx_image(data, &data->sprite[3], "textures/sprites/ghost4.xpm");
	create_mlx_image(data, &data->sprite[4], "textures/sprites/ghost5.xpm");
	create_mlx_image(data, &data->sprite[5], "textures/sprites/ghost6.xpm");
	data->sprite_main_img = data->sprite[0];
}

void	intitalize_sprites(t_data *data)
{
	int	x;
	int	y;
	int	n;

	data->visible_sprites_num = 0;
	data->sprites = malloc(sizeof(t_sprite) * data->sprite_num);
	check_ptr(data->sprites, "sprites");
	n = 0;
	y = 0;
	while (data->map[y] && n < data->sprite_num)
	{
		x = 0;
		while (data->map[y][x] && n < data->sprite_num)
		{
			if (data->map[y][x] == SPRITE)
			{
				data->sprites[n].pos.x = (x * T_SIZE) + (T_SIZE / 2);
				data->sprites[n].pos.y = (y * T_SIZE) + (T_SIZE / 2);
				n++;
			}
			x++;
		}
		y++;
	}
}
