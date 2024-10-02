/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 19:35:49 by ebennamr          #+#    #+#             */
/*   Updated: 2023/07/11 12:53:52 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	i_ternary(int condition, int is_true, int is_false)
{
	if (condition)
		return (is_true);
	else
		return (is_false);
}

double	d_ternary(int condition, double is_true, double is_false)
{
	if (condition)
		return (is_true);
	else
		return (is_false);
}

int	is_inside(t_point point, double width, double height)
{
	if (point.x < 0 || point.x >= width || point.y < 0 || point.y >= height)
		return (0);
	else
		return (1);
}

int	is_rgb(int rgb)
{
	return (rgb >= 0 && rgb <= 255);
}

void	fix_angle(double *angle)
{
	if (*angle > 2 * M_PI)
		*angle = *angle - (2 * M_PI);
	if (*angle < 0)
		*angle = (2 * M_PI) + *angle;
}
