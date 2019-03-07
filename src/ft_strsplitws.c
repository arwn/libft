/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplitws.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 13:25:08 by awindham          #+#    #+#             */
/*   Updated: 2019/03/07 14:51:28 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

static int		wordlen(char const *str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i] < 33)
		i++;
	while (str[i] >= 33 && str[i++] != '\0')
		len++;
	return (len);
}

int				ft_countwordsws(char const *str)
{
	int count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] < 33 && str[i] != 0)
			i++;
		if (str[i] >= 33 && str[i] != '\0')
			count++;
		while (str[i] >= 33 && str[i] != '\0')
			i++;
	}
	return (count);
}

char			**ft_strsplitws(char const *s)
{
	int		i;
	int		j;
	int		k;
	char	**an_eggy_boy;

	if (s == 0 || (an_eggy_boy = malloc(sizeof(*an_eggy_boy) *
					(ft_countwordsws(s) + 1))) == 0)
		return (0);
	i = -1;
	j = 0;
	while (++i < ft_countwordsws(s))
	{
		k = 0;
		if ((an_eggy_boy[i] = ft_strnew(wordlen(&s[j]) + 1)) == 0)
			an_eggy_boy[i] = 0;
		while (s[j] < 33)
			j++;
		while (s[j] >= 33 && s[j])
			an_eggy_boy[i][k++] = s[j++];
		an_eggy_boy[i][k] = '\0';
	}
	an_eggy_boy[i] = 0;
	return (an_eggy_boy);
}
