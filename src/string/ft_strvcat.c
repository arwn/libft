/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strvcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 10:23:52 by zfaria            #+#    #+#             */
/*   Updated: 2019/05/08 10:23:52 by zfaria           ###   ########.fr       */
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
