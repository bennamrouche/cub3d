/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_content_ex_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  ebennamr <ebennamr@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 13:11:02 by mel-aini          #+#    #+#             */
/*   Updated: 2023/07/18 13:37:17 by  ebennamr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void	init(char **map, t_list *content, int i, int map_width)
{
	int	j;
	int	len;

	map[i] = malloc(sizeof(char) * (map_width + 1));
	check_ptr(map[i], ERR_OUT_OF_MEM);
	j = 0;
	len = ft_strlen(content->content);
	while (j < map_width)
	{
		if (j < len)
			map[i][j] = *((char *)content->content + j);
		else
			map[i][j] = ' ';
		j++;
	}
	map[i][j] = '\0';
}

char	**get_map(t_list *content, int map_width)
{
	char	**map;
	int		i;

	if (!content)
		error(ERR_INV_MAP);
	map = malloc(sizeof(char *) * (ft_lstsize(content) + 1));
	check_ptr(content, ERR_OUT_OF_MEM);
	i = 0;
	while (content)
	{
		init(map, content, i, map_width);
		content = content->next;
		i++;
	}
	map[i] = NULL;
	return (map);
}
