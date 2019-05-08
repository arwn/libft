/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 10:22:48 by zfaria            #+#    #+#             */
/*   Updated: 2019/05/08 10:22:49 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	char		*d;
	const char	*s;

	if (n != 0)
	{
		d = dst;
		s = src;
		n++;
		while (--n != 0)
		{
			if ((*d++ = *s++) == 0)
			{
				while (--n != 0)
					*d++ = 0;
				break ;
			}
		}
	}
	return (dst);
}
