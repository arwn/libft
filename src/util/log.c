/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 10:04:49 by zfaria            #+#    #+#             */
/*   Updated: 2019/03/27 10:21:51 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <unistd.h>
#include <fcntl.h>

int g_fd;

void	log_init(char *str)
{
	g_fd = open(str, O_RDWR | O_CREAT);
	atexit(log_close);
}

void	log_write(char *str)
{
	ft_putstr_fd(str, g_fd);
}

void	log_close(void)
{
	close(g_fd);
}
