/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 13:01:57 by zfaria            #+#    #+#             */
/*   Updated: 2018/12/02 18:13:36 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	int exists;
	int i;

	if (!*needle || haystack == needle || (!*haystack && !*needle))
		return ((char *)haystack);
	i = 0;
	while (*haystack)
	{
		if (*haystack == *needle)
		{
			exists = 1;
			i = 0;
			while (needle[i])
			{
				if (haystack[i] != needle[i])
					exists = 0;
				i++;
			}
			if (exists)
				return ((char *)haystack);
		}
		haystack++;
	}
	return (NULL);
}
