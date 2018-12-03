/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awindham <awindham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 20:40:34 by awindham          #+#    #+#             */
/*   Updated: 2018/12/02 11:56:19 by awindham         ###   ########.fr       */
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
