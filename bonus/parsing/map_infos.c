/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_infos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  ebennamr <ebennamr@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 14:57:55 by ebennamr          #+#    #+#             */
/*   Updated: 2023/07/18 14:19:08 by  ebennamr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	open_exs_cub(char *path)
{
	char	*tmp;
	int		fd;

	tmp = ft_strrchr(path, '.');
	if (tmp == NULL || strcmp(tmp, EXSTEN) != 0)
		return (error(ERR_INV_EXSTEN), -1);
	fd = open(path, O_RDONLY, 0644);
	if (fd == -1)
		error(ERR_OP_FILE);
	return (fd);
}

static int	getcolor(char *value, int i, int j)
{
	int		arr[3];
	char	**list;

	ft_bzero(arr, sizeof(int) * 3);
	if (char_count(value, ',') != 2)
		error(ERR_MAP_INF);
	list = ft_split(value, ',');
	check_ptr(list, ERR_OUT_OF_MEM);
	if (dp_size(list) != 3)
		error(ERR_INV_MAP);
	while (list[++i])
	{
			j = -1;
		while (list[i][++j])
		{
			if (!ft_isdigit(list[i][j]))
				error(ERR_MAP_INF);
			arr[i] = arr[i] * 10 + list[i][j] - 48;
		}
	}
	if (is_rgb(arr[0]) && is_rgb(arr[1]) && is_rgb(arr[2]))
		return (free_dp(list), (arr[0] << 16 | arr[1] << 8 | arr[2]));
	else
		return (error(ERR_MAP_INF), 0);
}

static	void	extract_info(char *key, char *value, t_pdata *data)
{
	if (ft_strcmp(key, "NO") == 0 && data->path_no == NULL)
		data->path_no = ft_strdup(value);
	else if (ft_strcmp(key, "SO") == 0 && data->path_so == NULL)
		data->path_so = ft_strdup(value);
	else if (ft_strcmp(key, "WE") == 0 && data->path_we == NULL)
		data->path_we = ft_strdup(value);
	else if (ft_strcmp(key, "EA") == 0 && data->path_ea == NULL)
		data->path_ea = ft_strdup(value);
	else if (ft_strcmp(key, "F") == 0 && data->color_flr == -1)
		data->color_flr = getcolor(value, -1, -1);
	else if (ft_strcmp(key, "C") == 0 && data->color_cl == -1)
		data->color_cl = getcolor(value, -1, -1);
	else
		error(ERR_MAP_INF);
}

static void	set_line(char *line, t_pdata *data)
{
	char		**list;
	static int	num_elment = 0;
	int			len;

	if (num_elment < 6 && is_empty(line) == 0)
	{
		list = ft_split(line, ' ');
		if (dp_size(list) != 2)
			error(ERR_MAP_INF);
		extract_info(list[0], list[1], data);
		free_dp(list);
		num_elment++;
	}
	else if (data->map_width != 0 || is_empty(line) == 0)
	{
		len = ft_strlen(line);
		ft_lstadd_back(&data->map, ft_lstnew(ft_strdup(line)));
		if (len > data->map_width)
			data->map_width = len;
	}
}

t_pdata	*parser(t_data *data, char *path)
{
	char		*line;
	char		*tmp;
	int			fd;
	t_pdata		*pdata;

	pdata = ft_calloc(1, sizeof(t_pdata));
	check_ptr(pdata, ERR_OUT_OF_MEM);
	pdata->color_cl = -1;
	pdata->color_flr = -1;
	fd = open_exs_cub(path);
	line = get_next_line(fd);
	check_ptr(line, ERR_EMPTY_FILE);
	while (line != NULL)
	{
		tmp = ft_strchr(line, '\n');
		if (tmp != NULL)
			*tmp = '\0';
		set_line(line, pdata);
		free(line);
		line = get_next_line(fd);
	}
	data->width = pdata->map_width;
	data->map = get_map(pdata->map, pdata->map_width);
	parse_map_content(data, pdata, data->map);
	return (pdata);
}
