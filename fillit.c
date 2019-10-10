/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoye <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 13:04:14 by djoye             #+#    #+#             */
/*   Updated: 2019/10/10 18:17:16 by djoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map		fillit(int count_fig, int x, int y, t_tetra *p, t_map *map)
{
	int		i;

	i = 0;
	if (i < (count_fig) && map->matrix[y][x] == '.' && push_figure(x, y, &p[i], map))
		return (fillit (count_fig, 0, 0, &p[++i], map));
	else if (i < (count_fig) && x <= (map->size - 2) && map->matrix[y][x + 1] == '.')
		return (fillit(count_fig, x + 1, y, &p[i], map));
	else if (i < (count_fig) && x == (map->size - 1) && y <= (map->size - 2) && map->matrix [y + 1][0] == '.')
		return (fillit(count_fig, 0, y + 1, &p[i], map));
//	if (i != count_fig)
//		get_matrix(count_fig, p, map);
	return (*map);
}
