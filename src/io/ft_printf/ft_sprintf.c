/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 10:59:30 by zfaria            #+#    #+#             */
/*   Updated: 2019/04/16 12:35:22 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>
#include <stdarg.h>
#include <libft.h>

int			ft_sprintf(char **str, const char *fmt, ...)
{
	va_list		args;
	int			res;
	t_vector	*vec;

	va_start(args, fmt);
	vec = read_fmt_str(fmt, args);
	va_end(args);
	*str = vec->v;
	res = vec->size;
	vectordel(&vec);
	return (res);
}
