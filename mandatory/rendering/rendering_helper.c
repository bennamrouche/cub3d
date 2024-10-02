/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  ebennamr <ebennamr@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 12:51:41 by ebennamr          #+#    #+#             */
/*   Updated: 2023/07/18 14:24:48 by  ebennamr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	create_image(t_data *data, t_img *image, int width, int height)
{
	if (image->img)
		mlx_destroy_image(data->mlx, image->img);
	image->img = mlx_new_image(data->mlx, width, height);
	if (!image->img)
		error(ERR_OUT_OF_MEM);
	image->width = width;
	image->height = height;
	image->addr = mlx_get_data_addr(image->img, &image->bits_per_pixel,
			&image->line_length, &image->endian);
	if (!image->addr)
		error(ERR_OUT_OF_MEM);
}

static void	create_mlx_image(t_data *data, t_img *image, char *file)
{
	if (image->img)
		mlx_destroy_image(data->mlx, image->img);
	image->img = mlx_xpm_file_to_image(data->mlx, file,
			&image->width, &image->height);
	if (!image->img)
		error(ERR_LOAD_TEX);
	image->addr = mlx_get_data_addr(image->img, &image->bits_per_pixel,
			&image->line_length, &image->endian);
	if (!image->addr)
		error(ERR_LOAD_TEX);
}

void	create_images(t_data *data, t_pdata *pdata)
{
	create_image(data, &data->view, SCREEN_WIDTH, SCREEN_HEIGHT);
	create_mlx_image(data, &data->wall_north, pdata->path_no);
	create_mlx_image(data, &data->wall_east, pdata->path_ea);
	create_mlx_image(data, &data->wall_south, pdata->path_so);
	create_mlx_image(data, &data->wall_west, pdata->path_we);
}

int	is_facing(double angle, int facing)
{
	if (facing == 1)
		return (angle > M_PI && angle < 2 * M_PI);
	else if (facing == 2)
		return (angle > 0 && angle < M_PI);
	else if (facing == 3)
		return (angle > 3 * M_PI / 2 || angle < M_PI / 2);
	else if (facing == 4)
		return (angle > M_PI / 2 && angle < 3 * M_PI / 2);
	else
		return (0);
}
