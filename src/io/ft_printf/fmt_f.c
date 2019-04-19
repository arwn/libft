/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_f.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 13:23:08 by zfaria            #+#    #+#             */
/*   Updated: 2019/04/18 11:09:23 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>
#include <libft.h>
#include <math.h>

#define ISINF(x) (ft_strstr(x, "inf") || ft_strstr(x, "INF"))
#define HASSIGN(x) (x[0] == '+' || x[0] == '-')

static char	*handle_alt(t_fmtarg *arg, char *str)
{
	if (arg->allsign)
	{
		if (str[0] != '-')
		{
			ft_memmove(str + 1, str, ft_strlen(str));
			str[0] = '+';
		}
	}
	if (arg->altfmt)
	{
		if (!ft_strchr(str, '.'))
			ft_strcat(str, ".");
	}
	return (str);
}

static char	*handle_precision(t_fmtarg *arg, long double d)
{
	if (arg->longflag)
	{
		if (d == HUGE_VALL)
			return (ft_strdup("inf"));
		if (d == -HUGE_VALL)
			return (ft_strdup("-inf"));
		if (arg->precisionb)
			return (ft_dtoa(d, arg->precision));
		else
			return (ft_dtoa(d, 6));
	}
	else
	{
		if (d == HUGE_VAL)
			return (ft_strdup("inf"));
		if (d == -HUGE_VAL)
			return (ft_strdup("-inf"));
		if (arg->precisionb)
			return (ft_dtoa((double)d, arg->precision));
		else
			return (ft_dtoa((double)d, 6));
	}
}

static void	handle_padding2(t_fmtarg *arg, char *str, char *news)
{
	int len;
	int	sp;
	int o;

	len = ft_strlen(str);
	sp = 0;
	o = 0;
	if (arg->zeroflag && !arg->leftalign && arg->padding > 0 &&
		!ISINF(str))
		ft_memset(news, '0', arg->padding);
	else
		ft_memset(news, ' ', arg->padding);
	if ((str[0] == '-' || str[0] == '+') && !arg->leftalign && arg->zeroflag
		&& !ISINF(str) && (o = 1))
		news[0] = str[0];
	else if ((str[0] == '-' || str[0] == '+') && arg->leftalign && (o = 1))
		news[0] = str[0];
	else if (HASSIGN(str) && arg->zeroflag && !ISINF(str) && (o = 1))
		news[0] = str[0];
	else if (arg->spaceflag && !(str[0] == '-' || str[0] == '+') && (sp = 1))
		news[0] = ' ';
	if (arg->leftalign)
		ft_memcpy(news + o + sp, str + o, len - o);
	else if (arg->padding > 0)
		ft_memcpy(news + (arg->padding - len) + o, str + o, len - o);
}

static char	*handle_padding(t_fmtarg *arg, char *str)
{
	char	*news;
	int		len;
	int		o;
	int		sp;

	o = 0;
	sp = 0;
	len = ft_strlen(str);
	if (arg->padding > len)
	{
		news = ft_memalloc(arg->padding + 1);
		handle_padding2(arg, str, news);
	}
	else if (arg->spaceflag && !(str[0] == '-' || str[0] == '+'))
	{
		news = ft_memalloc(len + 2);
		news[0] = ' ';
		ft_strcat(news, str);
	}
	else
		return (str);
	free(str);
	return (news);
}

void		*fmt_f(t_fmtarg *arg, va_list varg)
{
	t_result	*res;
	double		val;
	long double	val2;

	(void)arg;
	res = ft_memalloc(sizeof(t_result));
	if (arg->longflag)
	{
		val2 = va_arg(varg, long double);
		res->str = handle_precision(arg, val2);
	}
	else
	{
		val = va_arg(varg, double);
		res->str = handle_precision(arg, val);
	}
	res->str = handle_alt(arg, res->str);
	res->str = handle_padding(arg, res->str);
	res->bytes = ft_strlen(res->str);
	return (res);
}
