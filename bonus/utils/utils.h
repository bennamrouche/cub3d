/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  ebennamr <ebennamr@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 17:56:50 by ebennamr          #+#    #+#             */
/*   Updated: 2023/07/18 14:14:49 by  ebennamr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include "../cub3d.h"
//--------------> error >---------------------------->
# define EXSTEN ".cub"
# define ERROR "Error\n"
# define ERR_INV_EXSTEN "invalid extension, support only '.cub'"
# define ERR_OP_FILE "map file not open"
# define ERR_MAP_INF "invalid map information"
# define ERR_FL_TEXTURE "texture file not found"
# define ERR_INV_MAP "invalid map"
# define ERR_OUT_OF_MEM "out of momery \n"
# define ERR_LOAD_TEX "can't load texture \n"
# define ERR_NUM_ARG "Invalid args number"
# define ERR_EMPTY_FILE "empty file !"

typedef struct s_data	t_data;
typedef struct s_point	t_point;
typedef struct s_img	t_img;
typedef struct s_cast	t_cast;
typedef struct s_sprite	t_sprite;
typedef struct s_pdata	t_pdata;

void	check_ptr(void *ptr, char *err);
void	error(char *err);
void	error_deb(char *err, int line, char *file);
int		isempty(char *line);
void	free_dp(char **pt);
int		char_count(char *str, char c);
int		dp_size(char **pt);

//---------------------> untils <-------------->
int		i_ternary(int condition, int is_true, int is_false);
double	d_ternary(int condition, double is_true, double is_false);
int		is_inside(t_point point, double width, double height);
int		is_rgb(int rgb);
double	distance(t_point p1, t_point p2);
void	initialize(t_data *data, t_pdata *pdata);
void	create_images(t_data *data, t_pdata *pdata);
void	create_portal_images(t_data *data);
void	create_sprite_images(t_data *data);
void	intitalize_sprites(t_data *data);
void	create_mlx_image(t_data *data, t_img *image, char *file);
void	free_list(t_list *head);
#endif
