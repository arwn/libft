/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 10:20:30 by zfaria            #+#    #+#             */
/*   Updated: 2019/05/08 10:20:30 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*a;
	const unsigned char	*b;
	size_t				i;

	a = (const unsigned char*)s1;
	b = (const unsigned char*)s2;
	i = 0;
	while (i < n)
		if (a[i] == b[i])
			i++;
		else
			return (a[i] - b[i]);
	return (0);
}
