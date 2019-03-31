/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 09:34:34 by zfaria            #+#    #+#             */
/*   Updated: 2019/03/31 11:32:07 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include "libft.h"

#define FD_MAX 5000

static int		read_next_line(const int fd, char **thread, size_t buff_size)
{
	char	*buf;
	size_t	status;

	buf = ft_strnew(buff_size);
	if (!buf)
		return (-1);
	status = 0;
	while (!ft_strchr(*thread, '\n') && (status = read(fd, buf, buff_size)) > 0)
	{
		*thread = ft_fstrjoin(*thread, buf, 1);
		ft_strclr(buf);
	}
	ft_strdel(&buf);
	if (status < buff_size)
		return (0);
	return (1);
}

static int		grab_line(char **thread, char **line)
{
	int	i;

	i = ft_strchri(*thread, '\n');
	if (i == -1)
	{
		*line = ft_strdup(*thread);
		ft_strclr(*thread);
		return (0);
	}
	*line = ft_strnew(i);
	ft_memcpy(*line, *thread, i);
	ft_memmove(*thread, *thread + i + 1, ft_strlen(*thread) - i);
	return (1);
}

int				get_next_line(const int fd, char **line, size_t buff_size)
{
	static char	*threads[FD_MAX];
	int			status;
	int			readstatus;

	if (fd < 0 || fd >= FD_MAX)
		return (-1);
	if (read(fd, threads[fd], 0) == -1)
		return (-1);
	if (line == NULL)
		return (-1);
	if (!threads[fd])
	{
		threads[fd] = ft_strnew(buff_size);
		if (!threads[fd] && !*line)
			return (-1);
	}
	readstatus = read_next_line(fd, &threads[fd], buff_size);
	status = grab_line(&threads[fd], line);
	if (readstatus == 0 && status == 0 && !**line)
	{
		freev(*line, threads[fd], 0);
		return (0);
	}
	else
		return (1);
}
