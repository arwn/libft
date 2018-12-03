/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awindham <awindham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 11:50:12 by awindham          #+#    #+#             */
/*   Updated: 2018/12/02 11:50:14 by awindham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putendl_fd(char *s, int fd)
{
	if (fd < 0 || s == 0 || fd > 65535)
		return ;
	while (*s)
		if (write(fd, s++, 1) < 0)
			return ;
	if (write(fd, "\n", 1) < 0)
		return ;
}
