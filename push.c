/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uheirloo <uheirloo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:39:16 by djoye             #+#    #+#             */
/*   Updated: 2019/10/12 16:32:19 by djoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		push_figure(int x, int y, t_tetra *p, t_map *map)
{
	if ((x + p->x[0] >= 0 && y + p->y[0] >= 0 && x + p->x[0] < map->size &&
			y + p->y[0] < map->size &&
			map->matrix[y + p->y[0]][x + p->x[0]] == '.') &&
			(x + p->x[1] >= 0 && y + p->y[1] >= 0 && x + p->x[1] < map->size &&
			y + p->y[1] < map->size &&
			map->matrix[y + p->y[1]][x + p->x[1]] == '.') &&
			(x + p->x[2] >= 0 && y + p->y[2] >= 0 && x + p->x[2] < map->size &&
			y + p->y[2] < map->size &&
			map->matrix[y + p->y[2]][x + p->x[2]] == '.'))
	{
		map->matrix[y][x] = p->letter;
		map->matrix[y + p->y[0]][x + p->x[0]] = p->letter;
		map->matrix[y + p->y[1]][x + p->x[1]] = p->letter;
		map->matrix[y + p->y[2]][x + p->x[2]] = p->letter;
		return (1);
	}
	return (0);
}
