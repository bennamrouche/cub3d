/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  ebennamr <ebennamr@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 14:31:38 by mel-aini          #+#    #+#             */
/*   Updated: 2023/07/18 13:08:57 by  ebennamr        ###   ########.fr       */
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

# define NUM_FRAMES  40
# define PORTAL_IMGS 10
# define SPRITE_IMGS 6
# define EPSILON	 0.2

# define WALL 	'1'
# define FLOOR 	'0'
# define SPACE 	' '
# define PORTAL	'P'
# define DOOR	'D'
# define SPRITE	'G'

# define FOV			1.0472
# define T_SIZE		16
# define SCREEN_WIDTH	1440
# define SCREEN_HEIGHT	1080
# define MAP_WIDTH		150
# define MAP_HEIGHT		150
# define MAP_CENTER		75
# define NUM_RAYS 		SCREEN_WIDTH

# define MAP_BORDER		0x1f4860
# define MAP_FLOOR		0x5E6A82
# define MAP_DOOR		0x361C29
# define MAP_WALL		0x162135
# define MAP_PORTAL		0x375182
# define MAP_EMPTY		0x100014
# define PLAYER_COLOR	0xf5cb5c

# define GAP	20

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
	bool	is_hit_door;
	bool	is_hit_portal;
	bool	is_hit_sprite;
	double	distance_to_wall;
}				t_cast;

typedef struct s_portal
{
	t_img	main_img;
	t_img	portal1;
	t_img	portal2;
	t_img	portal3;
	t_img	portal4;
	t_img	portal5;
	t_img	portal6;
	t_img	portal7;
	t_img	portal8;
	t_img	portal9;
	t_img	portal10;
}				t_portal;

typedef struct s_sprite
{
	t_point	pos;
	double	angle;
	double	distance;
	bool	visible;
	double	top_y;
	double	bottom_y;
	double	left_x;
	double	right_x;
	double	height;
	double	width;
}				t_sprite;

typedef struct s_data
{
	t_point		player;
	t_cast		cast;
	t_img		view;
	t_img		minimap;
	t_img		wall_north;
	t_img		wall_south;
	t_img		wall_west;
	t_img		wall_east;
	t_img		img_door;
	t_sprite	*sprites;
	t_cast		*rays;
	t_img		*portal;
	t_img		*sprite;
	t_img		portal_main_img;
	t_img		sprite_main_img;
	t_list		*visible_sprites;
	t_img		*correct_wall;
	t_cast		*curr_ray;
	double		ray_ang;
	void		*mlx;
	void		*win;
	double		rotation_angle;
	int			turn_direction;
	int			walk_direction;
	int			width;
	int			height;
	int			last_mouse_x;
	double		alpha;
	char		**map;
	bool		key_pressed;
	double		wall_distance;
	int			portal_num;
	int			sprite_num;
	int			visible_sprites_num;
	int			frame;
	double		dis_to_pp;
	int			c_color;
	int			f_color;
	t_point		t_start;
	t_point		t_index;
	int			rand_n;
	int			swap;
	t_sprite	*sprite_tmp;
}				t_data;
#endif
