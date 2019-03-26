/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fstrjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 10:22:39 by zfaria            #+#    #+#             */
/*   Updated: 2018/12/05 10:29:22 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_fstrjoin(char *s1, char *s2, int num)
{
	char *retval;

	retval = ft_strjoin(s1, s2);
	if (num == 0)
	{
		ft_strdel(&s1);
		ft_strdel(&s2);
	}
	else if (num == 1)
		ft_strdel(&s1);
	else if (num == 2)
		ft_strdel(&s2);
	return (retval);
}
