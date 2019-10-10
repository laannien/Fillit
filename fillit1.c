/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uheirloo <uheirloo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 13:04:14 by djoye             #+#    #+#             */
/*   Updated: 2019/10/10 18:17:01 by uheirloo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map		*fillit(int count_fig, int x, int y, t_tetra *p, t_map *map)
{
	t_tetra *i;

	i = p;
	if (x < map->size && y < map->size && (map->matrix[y][x] == '.' 
			|| map->matrix[y][x] == 0))
	{
		if (push_figure(x, y, i, map) == 1)
		{
			i++;
			if (i == 0)
				return (map);
			else 
			{
				return (fillit(count_fig, 0, 0, i, map));
				if (x <= (map->size - 2))
					return (fillit(count_fig, x + 1, y, i, map));
				else if (x == (map->size - 1) && y <= (map->size - 2))
					return (fillit(count_fig, 0, y + 1, i, map));
				else if (x == (map->size - 1) && y == (map->size - 1))
					return (fillit(count_fig, 0, 0, p, get_matrix(count_fig, map)));
			}
		}
	}
	if (x <= (map->size - 2))
		return (fillit(count_fig, x + 1, y, i, map));
	else if (x == (map->size - 1) && y <= (map->size - 2))
		return (fillit(count_fig, 0, y + 1, i, map));
	else if (x == (map->size - 1) && y == (map->size - 1))
		return (fillit(count_fig, 0, 0, p, get_matrix(count_fig, map)));
	return (map);
//	else return (*get_matrix(count_fig, p, map));
}
