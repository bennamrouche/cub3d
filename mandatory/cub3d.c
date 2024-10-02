/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 14:27:15 by mel-aini          #+#    #+#             */
/*   Updated: 2023/07/12 10:36:39 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char *argv[])
{
	t_pdata	*pdata;
	t_data	data;

	if (argc != 2)
		error(ERR_NUM_ARG);
	pdata = parser(&data, argv[1]);
	if (pdata->map == NULL)
		error(ERR_INV_MAP);
	initialize(&data, pdata);
	mlx_hook(data.win, ON_KEYDOWN, 0, key_hook, &data);
	mlx_hook(data.win, ON_KEYUP, 0, key_release, &data);
	mlx_hook(data.win, ON_DESTROY, 0, destroy_win, &data);
	mlx_loop_hook(data.mlx, render, &data);
	mlx_loop(data.mlx);
}
