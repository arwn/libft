/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awindham <awindham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 17:46:50 by awindham          #+#    #+#             */
/*   Updated: 2018/11/30 16:59:48 by awindham         ###   ########.fr       */
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
