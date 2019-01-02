/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putarr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 12:51:49 by zfaria            #+#    #+#             */
/*   Updated: 2019/01/02 13:00:01 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putarr_fd(char **str, char c, int fd)
{
	if (str)
		while (*str)
		{
			ft_putstr_fd(*str++, fd);
			if (*str)
				ft_putchar_fd(c, fd);
		}
}
