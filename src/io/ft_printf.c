/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awindham <awindham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 14:07:49 by awindham          #+#    #+#             */
/*   Updated: 2019/02/20 14:34:54 by awindham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <libft.h>
#include <unistd.h>

static int	conversion(char c, va_list vargs)
{
	if (c == '%')
		ft_putchar(c);
	else if (c == 'c')
		ft_putchar(va_arg(vargs, int));
	else if (c == 's')
		ft_putstr(va_arg(vargs, char *));
	else if (c == 'd')
		ft_putnbr(va_arg(vargs, int));
	else
		ft_putchar(c);
	return (2);
}

static void	output(char *fmt, va_list vargs)
{
	if (fmt[0] == 0)
		return ;
	if (fmt[0] == '%')
		output(fmt + conversion(fmt[1], vargs), vargs);
	else
		output(fmt + write(1, fmt, 1), vargs);
}

void		ft_printf(char *fmt, ...)
{
	va_list args;

	va_start(args, fmt);
	output(fmt, args);
	va_end(args);
}
