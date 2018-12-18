/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awindham <awindham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 14:32:24 by awindham          #+#    #+#             */
/*   Updated: 2018/12/02 17:38:25 by awindham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>

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
