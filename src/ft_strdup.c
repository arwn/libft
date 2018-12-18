/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awindham <awindham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 14:26:42 by awindham          #+#    #+#             */
/*   Updated: 2018/11/29 14:53:08 by awindham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char const *s1)
{
	int			len;
	char const	*i;
	char		*ret;
	char		*oret;

	i = s1;
	while (*i)
		i++;
	len = i - s1;
	if ((oret = (char*)malloc((len + 1) * sizeof(char))) == NULL)
		return (NULL);
	ret = oret;
	while ((*ret = *s1++) != 0)
		ret++;
	*ret = '\0';
	return (oret);
}
