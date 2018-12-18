/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awindham <awindham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 18:22:45 by awindham          #+#    #+#             */
/*   Updated: 2018/12/10 20:54:25 by awindham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

/*
** TODO:
**	remove comments
**	死にたい
*/

int		get_next_line(const int fd, char **line)
{
	char				*line_buffer;
	static int			bytes_read;
	unsigned long int	i;

	if ((line_buffer = malloc(8192)) == 0 ||
			(read(fd, line_buffer, 0)) < 0 ||
			fd < 0)
		return (-1);
	i = 0;
	while ((bytes_read = read(fd, &line_buffer[i], 1)) > 0)
	{
		if (line_buffer[i] == '\n')
			break ;
		i++;
	}
	line_buffer[i] = 0;
	*line = line_buffer;
	return (bytes_read || (*line_buffer));
}
