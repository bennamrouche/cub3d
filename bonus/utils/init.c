/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  ebennamr <ebennamr@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 10:50:54 by mel-aini          #+#    #+#             */
/*   Updated: 2023/07/18 12:23:47 by  ebennamr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	create_image(t_data *data, t_img *image, int width, int height)
{
	image->img = mlx_new_image(data->mlx, width, height);
	if (!image->img)
		error(ERR_OUT_OF_MEM);
	image->width = width;
	image->height = height;
	image->addr = mlx_get_data_addr(image->img, &image->bits_per_pixel, \
	&image->line_length, &image->endian);
	if (!image->addr)
		error(ERR_OUT_OF_MEM);
}

void	create_mlx_image(t_data *data, t_img *image, char *file)
{
	image->img = mlx_xpm_file_to_image(data->mlx, file, \
	&image->width, &image->height);
	if (!image->img)
		error(ERR_LOAD_TEX);
	image->addr = mlx_get_data_addr(image->img, &image->bits_per_pixel, \
	&image->line_length, &image->endian);
	if (!image->addr)
		error(ERR_LOAD_TEX);
}

void	create_images(t_data *data, t_pdata *pdata)
{
	create_image(data, &data->view, SCREEN_WIDTH, SCREEN_HEIGHT);
	create_image(data, &data->minimap, MAP_WIDTH, MAP_HEIGHT);
	create_mlx_image(data, &data->wall_north, pdata->path_no);
	create_mlx_image(data, &data->wall_south, pdata->path_so);
	create_mlx_image(data, &data->wall_west, pdata->path_we);
	create_mlx_image(data, &data->wall_east, pdata->path_ea);
	create_portal_images(data);
	create_sprite_images(data);
	create_mlx_image(data, &data->img_door, "textures/door3.xpm");
}

void	initialize(t_data *data, t_pdata *pdata)
{
	data->mlx = mlx_init();
	check_ptr(data->mlx, ERR_OUT_OF_MEM);
	data->win = mlx_new_window(data->mlx, \
	SCREEN_WIDTH, SCREEN_HEIGHT, "cub3D_bonus");
	check_ptr(data->mlx, ERR_OUT_OF_MEM);
	data->turn_direction = 0;
	data->walk_direction = 0;
	data->dis_to_pp = (SCREEN_WIDTH / 2) / tan(FOV / 2);
	data->last_mouse_x = -1;
	data->rays = malloc(sizeof(t_cast) * NUM_RAYS);
	data->c_color = pdata->color_cl;
	data->f_color = pdata->color_flr;
	check_ptr(data->rays, "rays");
	create_images(data, pdata);
	intitalize_sprites(data);
}
