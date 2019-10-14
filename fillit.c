/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uheirloo <uheirloo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 13:04:14 by djoye             #+#    #+#             */
/*   Updated: 2019/10/14 15:49:46 by uheirloo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		push_figure(int x, int y, t_tetra *p, t_map *map)
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

int				fillit(t_tetra *p, t_map *map)
{
	int		x;
	int		y;

	y = 0;
	while (y < map->size)
	{
		x = 0;
		while (x < map->size)
		{
			if (map->matrix[y][x] == '.' && push_figure(x, y, p, map))
			{
				if (!p->next)
					return (1);
				if (fillit(p->next, map))
					return (1);
				map->matrix[y][x] = '.';
				map->matrix[y + p->y[0]][x + p->x[0]] = '.';
				map->matrix[y + p->y[1]][x + p->x[1]] = '.';
				map->matrix[y + p->y[2]][x + p->x[2]] = '.';
			}
			x++;
		}
		y++;
	}
	return (0);
}
