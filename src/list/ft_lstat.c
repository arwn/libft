/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 15:45:40 by zfaria            #+#    #+#             */
/*   Updated: 2019/03/25 15:59:07 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_lstat(t_list *list, int index)
{
	int i;

	i = 0;
	while (i < index && list)
	{
		list = list->next;
		i++;
	}
	if (list)
		return (list->content);
	return (0);
}
