/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strvcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awindham <awindham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 12:10:02 by awindham          #+#    #+#             */
/*   Updated: 2019/03/06 12:10:04 by awindham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdarg.h>

char	*ft_strvcat(char *s, ...)
{
	va_list	vargs;
	char	*a;

	va_start(vargs, s);
	while ((a = va_arg(vargs, char*)))
		s = ft_strcat(s, a);
	return (s);
}
