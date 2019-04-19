/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stypes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 14:21:20 by zfaria            #+#    #+#             */
/*   Updated: 2019/04/17 12:17:29 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>
#include <libft.h>

void	*cast_reg(t_fmtarg *arg, va_list varg, int base)
{
	int32_t	res;

	res = va_arg(varg, int32_t);
	if (base == 10)
	{
		if (arg->u)
			return (ft_uitoa((uint32_t)res));
		else
			return (ft_itoa(res));
	}
	else
		return (ft_itoa_base((uint32_t)res, base, arg->cas));
}

void	*cast_hh(t_fmtarg *arg, va_list varg, int base)
{
	int8_t	res;

	res = va_arg(varg, int32_t);
	if (base == 10)
	{
		if (arg->u)
			return (ft_uitoa((uint8_t)res));
		else
			return (ft_itoa(res));
	}
	else
		return (ft_itoa_base((uint8_t)res, base, arg->cas));
}

void	*cast_h(t_fmtarg *arg, va_list varg, int base)
{
	int16_t	res;

	res = va_arg(varg, int32_t);
	if (base == 10)
	{
		if (arg->u)
			return (ft_uitoa((uint16_t)res));
		else
			return (ft_itoa(res));
	}
	else
		return (ft_itoa_base((uint16_t)res, base, arg->cas));
}

void	*cast_l(t_fmtarg *arg, va_list varg, int base)
{
	int64_t	res;

	res = va_arg(varg, int64_t);
	if (base == 10)
	{
		if (arg->u)
			return (ft_uitoa((uint64_t)res));
		else
			return (ft_itoa(res));
	}
	else
		return (ft_itoa_base((uint64_t)res, base, arg->cas));
}

void	*cast_ll(t_fmtarg *arg, va_list varg, int base)
{
	int64_t	res;

	res = va_arg(varg, int64_t);
	if (base == 10)
	{
		if (arg->u)
			return (ft_uitoa((uint64_t)res));
		else
			return (ft_itoa(res));
	}
	else
		return (ft_itoa_base((uint64_t)res, base, arg->cas));
}
