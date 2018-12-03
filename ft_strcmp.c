/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awindham <awindham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 14:42:18 by awindham          #+#    #+#             */
/*   Updated: 2018/12/02 16:07:51 by awindham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	if (*s1 == 0 || *s2 == 0)
		return ((unsigned char)*s1 - (unsigned char)*s2);
	return (ft_memcmp(s1, s2, ft_strlen(s1) > ft_strlen(s2) ? ft_strlen(s1) :
		ft_strlen(s2)));
}
