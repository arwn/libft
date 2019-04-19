/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_v.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 11:12:09 by zfaria            #+#    #+#             */
/*   Updated: 2019/04/16 12:29:27 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>
#include <libft.h>
#include <unistd.h>
#include <fcntl.h>

t_vector	*read_file(int fd, int bufsize)
{
	t_vector	*vec;
	char		*tmp;

	vec = make_vector();
	while (get_next_line(fd, &tmp, bufsize) > 0)
	{
		vectorcat(vec, tmp, ft_strlen(tmp));
		vectorcat(vec, "\n", 1);
		free(tmp);
	}
	return (vec);
}

void		*fmt_v(t_fmtarg *arg, va_list varg)
{
	t_result	*res;
	t_vector	*vec;
	int			fd;
	char		*astr;
	int			bsize;

	res = malloc(sizeof(t_result));
	if (arg->altfmt)
		fd = va_arg(varg, int);
	else
	{
		astr = va_arg(varg, char *);
		fd = open(astr, O_RDONLY);
		if (fd < 0)
			return (0);
	}
	bsize = 64;
	if (arg->padding > 0)
		bsize = arg->padding;
	vec = read_file(fd, bsize);
	res->str = vec->v;
	res->bytes = vec->size;
	free(vec);
	close(fd);
	return (res);
}
