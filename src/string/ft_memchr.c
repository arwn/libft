/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 10:20:26 by zfaria            #+#    #+#             */
/*   Updated: 2019/05/08 10:20:26 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(void const *str, int c, size_t n)
{
	const unsigned char *p;

	if (n != 0)
	{
		p = str;
		while (n-- != 0)
		{
			if (*p++ == (unsigned char)c)
				return ((void *)(p - 1));
		}
	}
	return (0);
}
