/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:02:24 by mel-aini          #+#    #+#             */
/*   Updated: 2022/11/22 16:02:11 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char			*buffer;
	int				bytes;
	static char		*holder;
	char			*tmp;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes = 1;
	while (bytes != 0 && !check_line(holder, '\n'))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
			return (free(buffer), free(holder), (NULL));
		buffer[bytes] = '\0';
		holder = join(holder, buffer);
	}
	tmp = holder;
	line = save(tmp, '\n');
	holder = remain(holder, '\n');
	return (free(tmp), free(buffer), line);
}
