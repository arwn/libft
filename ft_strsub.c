/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awindham <awindham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 21:36:45 by awindham          #+#    #+#             */
/*   Updated: 2018/12/02 11:53:03 by awindham         ###   ########.fr       */
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
