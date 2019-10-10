/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uheirloo <uheirloo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 12:52:11 by uheirloo          #+#    #+#             */
/*   Updated: 2019/10/10 14:44:24 by uheirloo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map	*clean_last_tetra(t_map *map, t_tetra *p, int x, int y)
{
		map->matrix[y][x] = '.';
		map->matrix[y + p->y[0]][x + p->x[0]] = '.';
		map->matrix[y + p->y[1]][x + p->x[1]] = '.';
		map->matrix[y + p->y[2]][x + p->x[2]] = '.';
		return (map);
}

t_map	*algorithm(t_map *map, t_tetra *figures, int count_figures)
{
	int x;
	int y;
	int push_fig;
	int i;

	y = 0;
	i = 0;
	push_fig = 0;
	while (y < map->size)
	{
		x = 0;
		while (x < map->size)
		{
			if (push_figure(x, y, &figures[i], map) == 1)
				push_fig++;
			i++;
		}
	}
	if (push_fig != count_figures)
	{
		clean_last_tetra(map, &figures[i], x, y);
		map = algorithm(get_matrix(count_figures, figures, map), figures, count_figures);
	}
	return (map);
}
