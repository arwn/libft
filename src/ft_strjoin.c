/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awindham <awindham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 15:47:00 by awindham          #+#    #+#             */
/*   Updated: 2018/12/02 11:56:01 by awindham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*fresh;

	if (s1 == 0 || s2 == 0)
		return (0);
	if ((fresh = malloc((ft_strlen(s1)
					+ ft_strlen(s2) + 1)
					* sizeof(char))) == 0)
		return (0);
	if (ft_strlen(s1))
		ft_memcpy(fresh, s1, ft_strlen(s1));
	if (ft_strlen(s2))
		ft_memcpy(fresh + ft_strlen(s1), s2, ft_strlen(s2));
	*(fresh + ft_strlen(s1) + ft_strlen(s2)) = '\0';
	return (fresh);
}
