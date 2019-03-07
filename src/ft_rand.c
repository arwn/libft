/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rand.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 09:38:37 by zfaria            #+#    #+#             */
/*   Updated: 2019/03/07 12:19:36 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int64_t	ft_rand(void)
{
	int		fd;
	int64_t	buf;

	fd = open("/dev/random", O_RDONLY);
	read(fd, &buf, 8);
	close(fd);
	return (buf);
}
