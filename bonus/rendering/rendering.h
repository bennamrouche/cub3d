/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:46:59 by mel-aini          #+#    #+#             */
/*   Updated: 2023/07/17 08:43:26 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERING_H
# define RENDERING_H

// rand_n = 1 + (rand() % (data->portal_num - 1));

# include "../cub3d.h"
# include <limits.h>
# define F_UP 1
# define F_DOWN 2
# define F_RIGHT 3
# define F_LEFT 4

typedef struct s_data	t_data;
typedef struct s_point	t_point;
typedef struct s_img	t_img;
typedef struct s_cast	t_cast;
typedef struct s_sprite	t_sprite;
typedef struct s_pdata	t_pdata;

void	initialize(t_data *data, t_pdata *pdata);
int		render(t_data *data);
void	draw_map(t_data *data);
void	draw_minimap(t_data *data);
void	draw_player(t_data *data);
void	fix_angle(double *angle);
void	update_player(t_data *data);
void	cast_rays(t_data *data);
void	my_mlx_pixel_put(t_img *data, int x, int y, unsigned int color);
int		wall_at3(double x, double y, t_data *data);
int		wall_at(double x, double y, t_data *data);
void	draw_rectangle(t_data *data, int x, int y, int color);
void	draw_circle(t_data *data, double R, int color);
void	draw_line(t_data *data, t_point p2, int color, double ang);
void	draw_floor_and_ceil(t_data *data, t_point p1, t_point p2, int color);
void	render_textures(t_data *data, int view_x, t_cast *ray);
int		is_facing(double angle, int facing);
void	render_sprites(t_data *data);
void	draw_texture(t_data *data, t_sprite *sprite, t_img img);
int		sorted_list(t_list *head);
void	ft_swap(t_sprite **a, t_sprite **b);
int		swapped(t_list **head, t_sprite *sprite, t_list *tmp, int i);
void	door_auto_close_open(t_data *data, t_cast cast);
char	get_at(double x, double y, t_data *data, t_cast *ray);
int		is_facing(double angle, int facing);
int		wall_at_pixel(double x, double y, t_data *data);
void	render_floor_and_ceil(t_data *data, int view_x, t_cast *ray);
void	render_walls(t_data *data, double x, double y, int view_x);
void	get_sprite_img(t_data *data);
void	portal_transition(t_data *data);
void	get_portal_img(t_data *data);

#endif
