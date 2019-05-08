/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 10:20:15 by zfaria            #+#    #+#             */
/*   Updated: 2019/05/08 10:20:16 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	size_t	i;
	char	*big_meme_daddy;

	big_meme_daddy = malloc(size);
	if (big_meme_daddy == 0)
		return (0);
	else
	{
		i = 0;
		while (i < size)
			big_meme_daddy[i++] = 0;
	}
	return (big_meme_daddy);
}
