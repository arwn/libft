/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printpad.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awindham <awindham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 12:04:12 by awindham          #+#    #+#             */
/*   Updated: 2019/02/28 20:31:24 by awindham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <libft.h>

/*
** this function right aligns text with a delimeter
** vargs must be null terminated.
*/

void	ft_printpad(int w, char *delim, int align, ...)
{
	va_list	args;
	char	*s;
	int		i;

	va_start(args, align);
	while ((s = va_arg(args, char *)) != NULL)
	{
		i = 0;
		if (align == 'l')
			ft_putstr(s);
		while (i < (w - (int)ft_strlen(s)) / (int)ft_strlen(delim))
		{
			ft_putstr(delim);
			i++;
		}
		if (align == 'r')
		{
			ft_putstr(s);
			ft_putchar(' ');
		}
	}
	va_end(args);
}
