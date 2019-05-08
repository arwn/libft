/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 10:20:20 by zfaria            #+#    #+#             */
/*   Updated: 2019/05/08 10:20:21 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char unsigned		*dp;
	char const unsigned	*sp;
	char unsigned		uc;

	if (n)
	{
		dp = dst;
		sp = src;
		uc = c;
		while (n != 0)
		{
			if ((*dp++ = *sp++) == uc)
				return (dp);
			n--;
		}
	}
	return (0);
}
