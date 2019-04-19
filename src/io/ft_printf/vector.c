/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 15:07:28 by zfaria            #+#    #+#             */
/*   Updated: 2019/04/15 13:34:43 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <libftprintf.h>

t_vector	*vector_expand(t_vector *vector)
{
	char *new;

	vector->cap *= 2;
	new = ft_memalloc(vector->cap);
	ft_memcpy(new, vector->v, vector->size);
	free(vector->v);
	vector->v = new;
	return (vector);
}

t_vector	*make_vector(void)
{
	t_vector	*vec;

	vec = ft_memalloc(sizeof(t_vector));
	vec->size = 0;
	vec->cap = 8;
	vec->v = ft_memalloc(vec->cap);
	return (vec);
}

t_vector	*vectorcat(t_vector *vector, const char *str, size_t n)
{
	if (vector->size + n >= vector->cap)
	{
		vector_expand(vector);
		return (vectorcat(vector, str, n));
	}
	ft_memcpy(vector->v + vector->size, str, n);
	vector->size += n;
	return (vector);
}

void		vectordel(t_vector **vector)
{
	if (vector)
	{
		free((*vector)->v);
		free(*vector);
		*vector = 0;
	}
}
