/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 07:48:57 by mel-aini          #+#    #+#             */
/*   Updated: 2023/07/17 08:43:15 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

void	draw_line_texture(t_data *data, t_sprite *sprite, t_point text, int x)
{
	double	distance_from_top;
	char	*dst;
	int		y;
	t_img	img;

	img = data->sprite_main_img;
	y = sprite->top_y;
	while (y < sprite->bottom_y && y < SCREEN_HEIGHT)
	{
		distance_from_top = y + (sprite->height / 2) - (SCREEN_HEIGHT / 2);
		text.y = distance_from_top * (img.height / sprite->height);
		dst = img.addr + ((int)text.y * img.line_length \
		+ (int)text.x * (img.bits_per_pixel / 8));
		if (text.y >= 0 && sprite->distance < data->rays[x].distance_to_wall
			&& *(unsigned int *)dst != 0x00FF00)
			my_mlx_pixel_put(&data->view, x, y, *(unsigned int *)dst);
		y++;
	}
}

void	draw_texture(t_data *data, t_sprite *sprite, t_img img)
{
	t_point	texture;
	int		x;
	double	pixel_width;

	x = sprite->left_x;
	while (x < sprite->right_x && x < SCREEN_WIDTH)
	{
		if (x >= 0)
		{
			pixel_width = (img.width / sprite->width);
			texture.x = (x - sprite->left_x) * pixel_width;
			if (texture.x >= 0)
				draw_line_texture(data, sprite, texture, x);
		}
		x++;
	}
}

void	ft_swap(t_sprite **a, t_sprite **b)
{
	t_sprite	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	swapped(t_list **head, t_sprite *sprite, t_list *tmp, int i)
{
	t_sprite	*next;

	next = tmp->next->content;
	if (sprite->distance < next->distance)
	{
		ft_swap((t_sprite **)&tmp->content, (t_sprite **)&tmp->next->content);
		if (i == 0)
			*head = tmp;
		return (1);
	}
	return (0);
}
