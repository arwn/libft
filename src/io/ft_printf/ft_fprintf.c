/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 10:57:52 by zfaria            #+#    #+#             */
/*   Updated: 2019/04/15 13:35:25 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>
#include <stdarg.h>
#include <unistd.h>

int			ft_fprintf(int fd, const char *fmt, ...)
{
	va_list		args;
	int			res;
	t_vector	*vec;

	va_start(args, fmt);
	vec = read_fmt_str(fmt, args);
	va_end(args);
	res = write(fd, vec->v, vec->size);
	if (res < 0)
		return (-1);
	res = vec->size;
	vectordel(&vec);
	return (res);
}
