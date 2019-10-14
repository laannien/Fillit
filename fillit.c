/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uheirloo <uheirloo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 13:04:14 by djoye             #+#    #+#             */
/*   Updated: 2019/10/14 15:07:43 by uheirloo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	del_fig(int x, int y, t_tetra *p, t_map *map)
{
	map->matrix[y][x] = '.';
	map->matrix[y + p->y[0]][x + p->x[0]] = '.';
	map->matrix[y + p->y[1]][x + p->x[1]] = '.';
	map->matrix[y + p->y[2]][x + p->x[2]] = '.';
	return (1);
}

int			fillit(t_tetra *p, t_map *map)
{
	int		x;
	int		y;

	y = 0;
	while (y < map->size)
	{
		x = 0;
		while (x < map->size)
		{
			if (map->matrix[y][x] == '.')
			{
				if (push_figure(x, y, p, map))
				{
					if (!p->next)
						return (1);
					if (fillit(p->next, map))
						return (1);
					del_fig(x, y, p, map);
				}
			}
			x++;
		}
		y++;
	}
	return (0);
}
