/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 14:31:38 by mel-aini          #+#    #+#             */
/*   Updated: 2023/07/17 08:57:47 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include "get_next_line/get_next_line.h"
# include "lib/libft.h"
# include "./utils/utils.h"
# include "rendering/rendering.h"
# include "events/events.h"
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <mlx.h>
# include <string.h>
# include "parsing/parsing.h"
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>

# define WALL 	'1'
# define PLAYER 'P'
# define FLOOR 	'0'
# define SPACE 	' '

# define FOV			1.0472
# define T_SIZE		16
# define SCREEN_WIDTH	1440
# define SCREEN_HEIGHT	1080
# define NUM_RAYS 		SCREEN_WIDTH

typedef struct s_point
{
	double	x;
	double	y;
}				t_point;

typedef struct s_img
{
	int		width;
	int		height;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_cast
{
	double	ray_ang;
	t_point	intersect_h;
	t_point	intersect_v;
	t_point	clst_intrsct;
	int		hit_hor_wall;
	int		hit_ver_wall;
	int		is_ver;
	int		is_horz;
	double	wall_top;
	double	wall_bottom;
	double	wall_height;
	int		x_ratio;
}				t_cast;

typedef struct s_data
{
	t_point	player;
	t_cast	cast;
	t_img	view;
	t_img	wall_north;
	t_img	wall_south;
	t_img	wall_west;
	t_img	wall_east;
	void	*mlx;
	void	*win;
	double	rotation_angle;
	double	wall_distance;
	int		turn_direction;
	int		walk_direction;
	int		width;
	int		height;
	int		c_color;
	int		f_color;
	char	**map;
}				t_data;
#endif
