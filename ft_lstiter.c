/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awindham <awindham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 10:43:58 by awindham          #+#    #+#             */
/*   Updated: 2018/12/02 17:14:01 by awindham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *a_very_posh_lamp, void (*f)(t_list *elem))
{
	while (a_very_posh_lamp)
	{
		f(a_very_posh_lamp);
		a_very_posh_lamp = a_very_posh_lamp->next;
	}
}
