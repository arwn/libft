/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstapd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 11:44:47 by zfaria            #+#    #+#             */
/*   Updated: 2018/12/02 15:01:40 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstapd(t_list **alst, t_list *elem)
{
	t_list *begin_list;

	if (*alst)
	{
		begin_list = *alst;
		while ((*alst)->next)
			*alst = (*alst)->next;
		(*alst)->next = elem;
		*alst = begin_list;
	}
	else
		*alst = elem;
}
