/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awindham <awindham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 10:12:11 by awindham          #+#    #+#             */
/*   Updated: 2019/02/20 10:23:14 by awindham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/_types/_size_t.h>
#include <stdint.h>
#include <stdlib.h>
#include <libft.h>

/*
** fuck these stupid comments
** ft_realloc is not a reimplementation of realloc.
** ft_realloc is UNSAFE!
** DO NOT USE
*/

void	*ft_realloc(void *p, size_t o, size_t n)
{
	char *done;

	done = malloc(n);
	ft_bzero(done, n);
	ft_memcpy(done, p, o);
	free(p);
	return (done);
}
