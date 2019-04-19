/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 13:59:04 by z                 #+#    #+#             */
/*   Updated: 2019/04/15 13:30:03 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>
#include <stdio.h>
#include <libft.h>

static char	*handle_padding(t_fmtarg *arg, char *str)
{
	char	*news;
	int		len;

	len = ft_strlen(str);
	if (arg->padding > len)
	{
		news = ft_memalloc(arg->padding + 1);
		ft_memset(news, ' ', arg->padding);
		if (arg->leftalign)
			ft_memcpy(news, str, len);
		else
			ft_memcpy(news + (arg->padding - len), str, len);
		free(str);
	}
	else
	{
		return (str);
	}
	return (news);
}

static char	*handle_precision(t_fmtarg *arg, char *str)
{
	if (arg->precisionb)
	{
		if (arg->precision < ft_strlen(str))
		{
			str[arg->precision] = 0;
		}
	}
	return (str);
}

void		*fmt_s(t_fmtarg *arg, va_list varg)
{
	t_result	*res;
	char		*astr;

	res = malloc(sizeof(t_result));
	astr = va_arg(varg, char *);
	if (astr == 0)
	{
		res->str = ft_strdup("(null)");
		res->bytes = ft_strlen(res->str);
	}
	else
		res->str = ft_strdup(astr);
	res->str = handle_precision(arg, res->str);
	res->str = handle_padding(arg, res->str);
	res->bytes = ft_strlen(res->str);
	return (res);
}
