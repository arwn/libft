/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freev.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 13:24:21 by zfaria            #+#    #+#             */
/*   Updated: 2019/03/28 11:50:03 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>

void	freev(void *v, ...)
{
	va_list	vargs;
	void	*a;

	va_start(vargs, v);
	free(v);
	while ((a = va_arg(vargs, void*)))
	{
		if (a)
			free(a);
		a = 0;
	}
}
