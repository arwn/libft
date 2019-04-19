/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 14:25:56 by zfaria            #+#    #+#             */
/*   Updated: 2019/04/16 10:30:28 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*g_tab_lo = "0123456789abcdef";
static char *g_tab_up = "0123456789ABCDEF";

char	*ft_itoa_base(uint64_t n, int base, int cas)
{
	char	*res;
	int		i;
	char	*tab;

	if (n == 0)
		return (ft_strdup("0"));
	if (cas == 1)
		tab = g_tab_up;
	else
		tab = g_tab_lo;
	res = ft_strnew(65);
	i = 0;
	if (res)
	{
		while (n > 0)
		{
			res[i++] = tab[n % base];
			n /= base;
		}
		res[i] = 0;
		ft_strrev((unsigned char *)res);
	}
	return (res);
}
