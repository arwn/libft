/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 10:22:41 by zfaria            #+#    #+#             */
/*   Updated: 2019/05/08 10:22:41 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*fresh;
	int		i;

	if (s == 0)
		return (0);
	if ((fresh = malloc((ft_strlen(s) + 1) * sizeof(char const))) == 0)
		return (0);
	i = -1;
	while (s[++i])
		fresh[i] = f(i, s[i]);
	fresh[i] = '\0';
	return (fresh);
}
