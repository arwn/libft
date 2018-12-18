/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awindham <awindham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 11:59:20 by awindham          #+#    #+#             */
/*   Updated: 2018/12/02 17:14:52 by awindham         ###   ########.fr       */
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
