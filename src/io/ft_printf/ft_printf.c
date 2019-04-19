/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 13:42:50 by zfaria            #+#    #+#             */
/*   Updated: 2019/04/15 13:35:13 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>
#include <stdarg.h>
#include <unistd.h>

int			ft_printf(const char *fmt, ...)
{
	va_list		args;
	int			res;
	t_vector	*vec;

	va_start(args, fmt);
	vec = read_fmt_str(fmt, args);
	va_end(args);
	write(1, vec->v, vec->size);
	res = vec->size;
	vectordel(&vec);
	return (res);
}
