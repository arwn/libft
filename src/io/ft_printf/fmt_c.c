/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_c.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 13:59:04 by z                 #+#    #+#             */
/*   Updated: 2019/04/16 10:51:04 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>
#include <stdio.h>
#include <libft.h>

static char	*handle_padding(t_fmtarg *arg, t_result *res, char c)
{
	char	*news;

	if (arg->padding > 1)
	{
		res->bytes = arg->padding;
		news = ft_memalloc(arg->padding + 1);
		if (arg->zeroflag && !arg->leftalign)
			news = ft_memset(news, '0', arg->padding);
		else
			news = ft_memset(news, ' ', arg->padding);
		if (arg->leftalign)
			news[0] = c;
		else
			news[arg->padding - 1] = c;
		res->bytes = arg->padding;
	}
	else
	{
		news = ft_memalloc(2);
		news[0] = c;
		res->bytes = 1;
	}
	return (news);
}

void		*fmt_c(t_fmtarg *arg, va_list varg)
{
	t_result	*res;
	char		astr;

	res = malloc(sizeof(t_result));
	if (arg->perc)
		astr = '%';
	else
		astr = va_arg(varg, int);
	res->str = handle_padding(arg, res, astr);
	return (res);
}
