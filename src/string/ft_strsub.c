/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 10:23:43 by zfaria            #+#    #+#             */
/*   Updated: 2019/05/08 10:23:44 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*fresh;

	if (s == 0)
		return (0);
	if ((fresh = malloc((len + 1) * sizeof(*s))) == 0)
		return (0);
	ft_memmove(fresh, s + start, len);
	fresh[len] = '\0';
	return (fresh);
}
