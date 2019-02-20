/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printpad.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awindham <awindham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 12:04:12 by awindham          #+#    #+#             */
/*   Updated: 2019/02/20 12:35:37 by awindham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <libft.h>

/*
** this function right aligns text with a delimeter
** vargs must be null terminated.
*/

void	ft_printpad(int w, char *delim, ...)
{
	va_list args;
	char *s;
	int i;

	va_start(args, delim);
	while((s = va_arg(args, char *)) != NULL)
	{
		i = 0;
		while (i < (w - (int)ft_strlen(s)) / (int)ft_strlen(delim))
		{
			ft_putstr(delim);
			i++;
		}
		ft_putstr(s);
	}
}
