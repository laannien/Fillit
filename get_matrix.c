/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uheirloo <uheirloo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 20:54:28 by djoye             #+#    #+#             */
/*   Updated: 2019/10/14 17:44:17 by uheirloo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map		*get_matrix(int resize, t_map *map)
{
	int i;
	int j;

	if (resize == 1)
		map->size++;
	if (!(map->matrix = (char**)malloc(sizeof(char*) * (map->size + 1))))
		return (NULL);
	j = 0;
	while (j < map->size)
	{
		i = 0;
		if (!(map->matrix[j] = (char*)malloc(sizeof(char) * (map->size + 1))))
			return (NULL);
		while (i < map->size)
		{
			map->matrix[j][i] = '.';
			i++;
		}
		map->matrix[j][i] = '\0';
		j++;
	}
	map->matrix[j] = 0;
	return (map);
}
