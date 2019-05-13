/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 10:23:10 by zfaria            #+#    #+#             */
/*   Updated: 2019/05/13 12:45:29 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strrev(unsigned char *str)
{
	int				i;
	int				j;
	unsigned char	a;
	unsigned char	len;

	len = ft_strlen((const char *)str);
	i = 0;
	j = len - 1;
	while (i < j)
	{
		a = str[i];
		str[i] = str[j];
		str[j] = a;
		i++;
		j--;
	}
}
