/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 13:17:36 by zfaria            #+#    #+#             */
/*   Updated: 2019/03/01 14:17:09 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	free_tab(char **tab)
{
	if (tab)
	{
		while (*tab)
		{
			free(*tab);
			*tab = 0;
			tab++;
		}
		free(tab);
	}
}