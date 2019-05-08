/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 10:22:36 by zfaria            #+#    #+#             */
/*   Updated: 2019/05/08 10:22:37 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	const char	*src;
	char		*dst;

	if (n != 0)
	{
		src = s2;
		dst = s1;
		while (*dst != 0)
			dst++;
		while (n != 0)
		{
			if ((*dst = *src++) == 0)
				break ;
			dst++;
			n--;
		}
		*dst = 0;
	}
	return (s1);
}
