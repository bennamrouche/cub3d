/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:34:58 by mel-aini          #+#    #+#             */
/*   Updated: 2023/07/15 16:09:35 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../cub3d.h"

# define MAP_CHAR " 01NSEW"

typedef struct s_data	t_data;
typedef struct s_point	t_point;

typedef struct s_pdata
{
	char	*path_no;
	char	*path_so;
	char	*path_we;
	char	*path_ea;
	int		color_flr;
	int		color_cl;
	int		map_width;
	t_list	*map;
	int		start_y;
	int		start_x;
	int		end_y;
	int		end_x;
	char	*allowed_chars;
}				t_pdata;

t_pdata		*parser(t_data *data, char *path);
char		**get_map(t_list *content, int map_width);
char		**parse_map_content(t_data *data, t_pdata *pdata, char **map);
int			is_empty(char *line);
int			get_end_y(char **map);
int			get_start_x(char *line);
int			get_end_x(char *line, int start_x);
int			check_four_direction(char **map, int x, int y, int elem);
void		check_around(t_pdata *pdata, char **map, int x, int y);

#endif
