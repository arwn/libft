/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 10:22:30 by zfaria            #+#    #+#             */
/*   Updated: 2019/05/08 10:22:31 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*fresh;
	int		i;

	if (s == 0)
		return (0);
	if ((fresh = malloc((ft_strlen(s) + 1) * sizeof(char const))) == 0)
		return (0);
	i = -1;
	while (s[++i])
		fresh[i] = f(s[i]);
	fresh[i] = '\0';
	return (fresh);
}
