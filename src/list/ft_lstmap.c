/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 10:25:03 by zfaria            #+#    #+#             */
/*   Updated: 2019/05/08 10:25:04 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*jellyfish;
	t_list		*nlist;

	if (lst == 0)
		return (NULL);
	nlist = f(lst);
	jellyfish = nlist;
	while (lst->next)
	{
		lst = lst->next;
		if ((nlist->next = f(lst)) == 0)
		{
			free(nlist->next);
			return (NULL);
		}
		nlist = nlist->next;
	}
	return (jellyfish);
}
