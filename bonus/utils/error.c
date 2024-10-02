/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 17:55:53 by ebennamr          #+#    #+#             */
/*   Updated: 2023/07/12 10:57:01 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_ptr(void *ptr, char *err)
{
	if (ptr != NULL)
		return ;
	printf("%s%s\n", ERROR, err);
	exit(1);
}

void	error(char *err)
{
	if (err != NULL)
		printf("%s%s\n", ERROR, err);
	else
		printf("%s", ERROR);
	exit(1);
}
