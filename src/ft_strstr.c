/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awindham <awindham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 15:05:18 by awindham          #+#    #+#             */
/*   Updated: 2018/12/01 17:12:55 by awindham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char const *h, char const *n)
{
	if (!*n)
		return ((char*)h);
	while (ft_strncmp(h, n, ft_strlen(n)) && *h)
		h++;
	if (*h == '\0')
		return (0);
	else
		return ((char*)h);
}
