/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uheirloo <uheirloo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 13:15:47 by djoye             #+#    #+#             */
/*   Updated: 2019/10/10 14:29:43 by djoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map	*algo(int count_fig, t_tetra *p, t_map *map)
{
	int x;
	int y;
	int ind_fig;

	ind_fig = 0;
	y = 0;
	while (y < map->size)
	{
		x = 0;
		while (x < map->size)
		{
			if (map->matrix[y][x] == '.' && push_figure(x, y, &p[ind_fig], map))
			{
				if (++ind_fig == count_fig)
					return (map);
				x = 0;
				y = 0;
			}
			x++;
		}
		y++;
	}
	get_matrix(count_fig, p, map);
	return (map);
}
