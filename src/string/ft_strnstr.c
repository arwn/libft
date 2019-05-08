/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 10:23:06 by zfaria            #+#    #+#             */
/*   Updated: 2019/05/08 10:23:06 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strnstr(char const *hay, char const *nee, size_t len)
{
	size_t	i;

	if (!*nee)
		return ((char*)hay);
	else
	{
		while (*hay && len)
		{
			i = 0;
			while (hay[i] == nee[i] && i < len)
			{
				i++;
				if (!nee[i])
					return ((char*)hay);
			}
			len--;
			hay++;
		}
	}
	return (0);
}
