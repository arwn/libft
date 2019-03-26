/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awindham <awindham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 12:16:44 by awindham          #+#    #+#             */
/*   Updated: 2018/12/02 11:52:03 by awindham         ###   ########.fr       */
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
