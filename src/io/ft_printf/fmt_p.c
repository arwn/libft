/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 15:57:33 by zfaria            #+#    #+#             */
/*   Updated: 2019/04/16 19:32:58 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <libftprintf.h>

static char	*handle_alt(char *str, int orig)
{
	char	*news;
	int		len;

	len = ft_strlen(str);
	if (!orig)
	{
		news = ft_memalloc(len + 5);
		ft_strcpy(news, "0x");
		ft_strcat(news, str);
		free(str);
		return (news);
	}
	else if (orig)
	{
		free(str);
		return (ft_strdup("0x0"));
	}
	return (str);
}

static char	*handle_precision(t_fmtarg *arg, char *str, int o)
{
	char	*news;
	int		len;
	int		digl;

	len = ft_strlen(str);
	digl = len;
	if ((str[0] == '-' || str[0] == '+') && (o = 1))
		digl = len - 1;
	if (digl < arg->precision)
	{
		news = ft_memalloc(arg->precision + o + 1);
		ft_memset(news, '0', arg->precision + o);
		if (o)
			news[0] = str[0];
		ft_memcpy(news + o + (arg->precision - digl), str + o, len - o);
	}
	else if (arg->precision == 0 && arg->precisionb && str[0] == '0')
		news = ft_strdup("");
	else if (arg->precision == 0 && arg->precisionb && str[0] == '+')
		news = ft_strdup("+");
	else
		return (str);
	free(str);
	return (news);
}

static void	handle_padding2(t_fmtarg *arg, char *str, char *news)
{
	int len;
	int	sp;
	int o;

	len = ft_strlen(str);
	sp = 0;
	o = 0;
	if (arg->zeroflag && !arg->leftalign && !(arg->precision -
		arg->padding < 0 && arg->precisionb))
		ft_memset(news, '0', arg->padding);
	else
		ft_memset(news, ' ', arg->padding);
	if ((str[0] == '-' || str[0] == '+') && !arg->leftalign && arg->zeroflag
		&& arg->precisionb && arg->precision - 1 >= 0 && (o = 1))
		news[arg->padding - len] = str[0];
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

void		*fmt_p(t_fmtarg *arg, va_list varg)
{
	t_result	*res;
	int			origzero;
	uint64_t	ptrval;
	void		*ptr;

	res = ft_memalloc(sizeof(t_result));
	ptr = va_arg(varg, void *);
	ptrval = (uint64_t)ptr;
	origzero = 0;
	if (!ptr)
		origzero = 1;
	res->str = ft_itoa_base(ptrval, 16, 0);
	res->str = handle_precision(arg, res->str, 0);
	res->str = handle_alt(res->str, origzero);
	res->str = handle_padding(arg, res->str);
	res->bytes = ft_strlen(res->str);
	return (res);
}
