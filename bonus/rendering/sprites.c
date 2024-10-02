/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:24:44 by mel-aini          #+#    #+#             */
/*   Updated: 2023/07/17 16:32:45 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

void	get_sprite_img(t_data *data)
{
	int	a;
	int	selector;

	a = NUM_FRAMES / SPRITE_IMGS;
	selector = data->frame / a;
	if (selector < SPRITE_IMGS && selector >= 0)
		data->sprite_main_img = data->sprite[selector];
}

void	sort_visible_sprites(t_data *data, t_list **head)
{
	t_list		*tmp;
	int			i;

	data->swap = 1;
	while (data->visible_sprites_num > 1 && data->swap)
	{
		tmp = *head;
		i = 0;
		data->swap = 0;
		while (tmp)
		{
			data->sprite_tmp = tmp->content;
			if (tmp->next)
			{	
				if (swapped(head, data->sprite_tmp, tmp, i))
				{
					i++;
					data->swap = 1;
					continue ;
				}
				i++;
			}
			tmp = tmp->next;
		}
	}
}

void	detect_visible_sprites(t_data *data, t_list	**visible_sprites)
{
	int	i;

	i = -1;
	data->visible_sprites_num = 0;
	while (++i < data->sprite_num)
	{
		data->sprites[i].angle = data->rotation_angle - atan2(\
		data->sprites[i].pos.y - data->player.y, data->sprites[i].pos.x \
		- data->player.x);
		if (data->sprites[i].angle > M_PI)
			data->sprites[i].angle -= 2 * M_PI;
		if (data->sprites[i].angle < -M_PI)
			data->sprites[i].angle += 2 * M_PI;
		data->sprites[i].angle = fabs(data->sprites[i].angle);
		if (data->sprites[i].angle < (FOV / 2) + EPSILON)
		{
			data->sprites[i].visible = 1;
			data->sprites[i].distance = distance(data->player, \
			data->sprites[i].pos);
			ft_lstadd_back(visible_sprites, ft_lstnew(&data->sprites[i]));
			data->visible_sprites_num++;
		}
		else
			data->sprites[i].visible = 0;
	}
}

void	calc_and_render(t_data *data, t_list *visible_sprites)
{
	t_sprite	*sprite;
	double		sprite_angle;

	while (visible_sprites)
	{
		sprite = visible_sprites->content;
		sprite->height = (T_SIZE / sprite->distance) * data->dis_to_pp;
		sprite->width = sprite->height;
		sprite->top_y = (SCREEN_HEIGHT / 2) - (sprite->height / 2);
		if (sprite->top_y < 0)
			sprite->top_y = 0;
		sprite->bottom_y = sprite->top_y + sprite->height;
		if (sprite->bottom_y >= SCREEN_HEIGHT)
			sprite->bottom_y = SCREEN_HEIGHT - 1;
		sprite_angle = atan2(sprite->pos.y - data->player.y, sprite->pos.x \
		- data->player.x) - data->rotation_angle;
		sprite->left_x = (SCREEN_WIDTH / 2) + (tan(sprite_angle) * \
		data->dis_to_pp) - (sprite->width / 2);
		sprite->right_x = sprite->left_x + sprite->width;
		draw_texture(data, sprite, data->sprite_main_img);
		visible_sprites = visible_sprites->next;
	}
}

void	render_sprites(t_data *data)
{
	data->visible_sprites = NULL;
	detect_visible_sprites(data, &data->visible_sprites);
	sort_visible_sprites(data, &data->visible_sprites);
	calc_and_render(data, data->visible_sprites);
	free_list(data->visible_sprites);
}
