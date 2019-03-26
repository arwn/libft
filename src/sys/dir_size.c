/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 12:12:03 by zfaria            #+#    #+#             */
/*   Updated: 2019/02/28 20:22:14 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <stdlib.h>

int		dir_size(char *dirs)
{
	DIR				*dir;
	struct dirent	*entry;
	int				size;

	size = 0;
	dir = opendir(dirs);
	if (!dir)
		return (0);
	while ((entry = readdir(dir)) != NULL && entry->d_name[0] != 0)
		size++;
	closedir(dir);
	return (size);
}
