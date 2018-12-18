/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awindham <awindham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 13:25:08 by awindham          #+#    #+#             */
/*   Updated: 2018/12/01 15:39:09 by awindham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

static int		wordlen(char const *str, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i] == c)
		i++;
	while (str[i] != c && str[i++] != '\0')
		len++;
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**an_eggy_boy;

	if (s == 0 || (an_eggy_boy = malloc(sizeof(*an_eggy_boy) *
					(ft_countwords(s, c) + 1))) == 0)
		return (0);
	i = -1;
	j = 0;
	while (++i < ft_countwords(s, c))
	{
		k = 0;
		if ((an_eggy_boy[i] = ft_strnew(wordlen(&s[j], c) + 1)) == 0)
			an_eggy_boy[i] = 0;
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
			an_eggy_boy[i][k++] = s[j++];
		an_eggy_boy[i][k] = '\0';
	}
	an_eggy_boy[i] = 0;
	return (an_eggy_boy);
}
