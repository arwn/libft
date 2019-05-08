/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 10:21:51 by zfaria            #+#    #+#             */
/*   Updated: 2019/05/08 10:21:51 by zfaria           ###   ########.fr       */
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
