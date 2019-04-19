/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_dispatch2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 12:12:18 by zfaria            #+#    #+#             */
/*   Updated: 2019/04/17 16:10:22 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>
#include <libft.h>

void	*arg_spac(t_fmtarg *arg, va_list varg)
{
	(void)varg;
	arg->spaceflag = 1;
	return (0);
}

void	*arg_all(t_fmtarg *arg, va_list varg)
{
	(void)varg;
	arg->allsign = 1;
	return (0);
}

void	*arg_vfield(t_fmtarg *arg, va_list varg)
{
	int	val;

	val = va_arg(varg, int);
	arg->padding = val;
	return (0);
}

void	arg_prec(t_fmtarg *arg, char *temp)
{
	arg->precisionb = 1;
	arg->padding = ft_atoi(temp);
	ft_strclr(temp);
}
