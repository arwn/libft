/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_dispatch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 11:54:53 by zfaria            #+#    #+#             */
/*   Updated: 2019/04/17 12:17:34 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>
#include <libft.h>

void	*arg_long_inc(t_fmtarg *arg, va_list varg)
{
	(void)varg;
	arg->longflag++;
	return (0);
}

void	*arg_long_max(t_fmtarg *arg, va_list varg)
{
	(void)varg;
	arg->longflag = 2;
	return (0);
}

void	*arg_short_inc(t_fmtarg *arg, va_list varg)
{
	(void)varg;
	arg->shortflag++;
	return (0);
}

void	*arg_altfmt(t_fmtarg *arg, va_list varg)
{
	(void)varg;
	arg->altfmt = 1;
	return (0);
}

void	*arg_leftalign(t_fmtarg *arg, va_list varg)
{
	(void)varg;
	arg->leftalign = 1;
	return (0);
}
