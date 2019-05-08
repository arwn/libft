/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 10:20:43 by zfaria            #+#    #+#             */
/*   Updated: 2019/05/08 10:20:43 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*d;
	char	*s;
	size_t	one_unsigned_integer;

	if (src < dst)
		return (ft_memcpy(dst, src, n));
	else
	{
		d = (char*)dst;
		s = (char*)src;
		one_unsigned_integer = 0;
		while (one_unsigned_integer++ < n)
			d[one_unsigned_integer - 1] = s[one_unsigned_integer - 1];
	}
	return (dst);
}
