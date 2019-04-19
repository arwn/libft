/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 13:30:48 by zfaria            #+#    #+#             */
/*   Updated: 2019/04/13 13:31:52 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_uitoa(uint64_t n)
{
	char			*res;
	int				i;

	if (n == 0)
		return (ft_strdup("0"));
	res = ft_strnew(33);
	i = 0;
	if (res)
	{
		while (n > 0)
		{
			res[i++] = n % 10 + '0';
			n /= 10;
		}
		res[i] = 0;
		ft_strrev((unsigned char *)res);
	}
	return (res);
}
