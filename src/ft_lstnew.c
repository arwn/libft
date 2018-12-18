/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awindham <awindham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 09:53:14 by awindham          #+#    #+#             */
/*   Updated: 2018/12/02 16:47:29 by awindham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*big_boyo;

	if ((big_boyo = malloc(sizeof(*big_boyo))) == 0)
		return (NULL);
	if (content == 0)
	{
		big_boyo->content = 0;
		big_boyo->content_size = 0;
	}
	else
	{
		if ((big_boyo->content = malloc(content_size)) == 0)
			return (0);
		ft_memcpy(big_boyo->content, content, content_size);
		big_boyo->content_size = content_size;
	}
	big_boyo->next = 0;
	return (big_boyo);
}
