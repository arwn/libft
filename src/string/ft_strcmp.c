/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 10:21:37 by zfaria            #+#    #+#             */
/*   Updated: 2019/05/08 10:21:39 by zfaria           ###   ########.fr       */
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
