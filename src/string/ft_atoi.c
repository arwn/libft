/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 10:18:39 by zfaria            #+#    #+#             */
/*   Updated: 2019/05/08 10:18:44 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *s)
{
	long	n;
	int		neg;

	n = 0;
	neg = 0;
	while (ft_isspace(*s))
		s++;
	if (*s == '-')
	{
		neg = 1;
		s++;
	}
	else if (*s == '+')
		s++;
	while (ft_isdigit(*s))
	{
		n = (10 * n) - (*s++ - '0');
		if (n > 0)
			return (neg ? (int)-2147483648 : (int)2147483647);
	}
	return (neg ? (int)n : (int)-n);
}
