/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:46:59 by mel-aini          #+#    #+#             */
/*   Updated: 2023/07/15 08:04:35 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERING_H
# define RENDERING_H

# include "../cub3d.h"
# include <limits.h>
# define F_UP 1
# define F_DOWN 2
# define F_RIGHT 3
# define F_LEFT 4

typedef struct s_data	t_data;
typedef struct s_point	t_point;
typedef struct s_img	t_img;
typedef struct s_pdata	t_pdata;

void	create_images(t_data *data, t_pdata *pdata);
void	initialize(t_data *data, t_pdata *pdata);
int		render(t_data *data);
void	fix_angle(double *angle);
void	update_player(t_data *data);
void	cast_rays(t_data *data);
void	my_mlx_pixel_put(t_img *data, int x, int y, unsigned int color);
int		wall_at3(double x, double y, t_data *data);
int		wall_at(double x, double y, t_data *data);
void	draw_floor_and_ceil(t_data *data, t_point p1,
			t_point p2, int color);
void	render_textures(t_data *data, int view_x);
int		is_facing(double angle, int facing);
double	distance(t_point p1, t_point p2);
void	render_walls(t_data *data, double x, double y, int view_x);
#endif
