/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uheirloo <uheirloo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 20:54:28 by djoye             #+#    #+#             */
/*   Updated: 2019/10/10 14:50:25 by djoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	**fill_matrix(t_map *map)
{
	int i;
	int j;

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
	return (map->matrix);
}

t_map		*get_matrix(int count_fig, t_tetra *p, t_map *map)
{
	if (!(map->size))
	{
		map->size = 2;
		while (count_fig * 4 > map->size * map->size)
			map->size++;
	}
	else
		map->size++;
	if (!(map->matrix = (char**)malloc(sizeof(char*) * (map->size + 1))))
		return (NULL);
	if (!(map->matrix = fill_matrix(map)))
		return (NULL);
	*map = fillit(count_fig, 0, 0, &p[0], map);
	return (map);
}
