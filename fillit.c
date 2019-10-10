/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoye <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 13:04:14 by djoye             #+#    #+#             */
/*   Updated: 2019/10/10 16:07:08 by djoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map		fillit(int count_fig, int x, int y, t_tetra *p, t_map *map)
{
	int		ind_fig;

	ind_fig = 0;
	if (x < map->size && y < map->size && (map->matrix[y][x] == '.' 
			|| map->matrix[y][x] == 0
																))
	{
		if ((x + p->x[0] >= 0 && y + p->y[0] >= 0 && x + p->x[0] < map->size &&
					y + p->y[0] < map->size &&
					(map->matrix[y + p->y[0]][x + p->x[0]] == '.' 
					 || map->matrix[y + p->y[0]][x + p->x[0]] == 0
					 )) &&
				(x + p->x[1] >= 0 && y + p->y[1] >= 0 &&
				 x + p->x[1] < map->size && y + p->y[1] < map->size &&
				 (map->matrix[y + p->y[1]][x + p->x[1]] == '.'
				  || map->matrix[y + p->y[1]][x + p->x[1]] == 0
				  )) &&
				(x + p->x[2] >= 0 && y + p->y[2] >= 0 &&
				 x + p->x[2] < map->size && y + p->y[2] < map->size &&
				 (map->matrix[y + p->y[2]][x + p->x[2]] == '.' 
				  || map->matrix[y + p->y[2]][x + p->x[2]] == 0
			)))
		{
			map->matrix[y][x] = p->letter;
			map->matrix[y + p->y[0]][x + p->x[0]] = p->letter;
			map->matrix[y + p->y[1]][x + p->x[1]] = p->letter;
			map->matrix[y + p->y[2]][x + p->x[2]] = p->letter;
		}
		if (++ind_fig == count_fig)
			return (*map);
		else return (fillit (count_fig, 0, 0, &p[ind_fig], map));
	}
	if (x <= (map->size - 2))
		return (fillit(count_fig, x + 1, y, &p[ind_fig], map));
	else if (x == (map->size -1) && y <= (map->size - 2))
		return (fillit(count_fig, 0, y + 1, &p[ind_fig], map));
	else if (x == (map->size - 1) && y == (map->size - 1) && ind_fig > 0)
		return (fillit(count_fig, 0, 0, &p[--ind_fig], map));
	else return (*map);
//	else return (*get_matrix(count_fig, p, map));
}
