/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoye <djoye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 13:04:14 by djoye             #+#    #+#             */
/*   Updated: 2019/10/10 20:45:11 by djoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map		*fillit(int count_fig, int x, int y, t_tetra *p, t_map *map)
{
	int		i;
	int		l;
	t_map	*c_map;

	i = 0;
	c_map = map;
	if (&p[i] == 0)
			return (c_map);
	if (map->matrix[y][x] == '.' && push_figure(x, y, &p[i], map))
	{
		i++;
		l = 0;
		while (l < map->size)
		{
			printf("%s\n", map->matrix[l]);
			l++;
		}
		printf("\n");
		c_map = fillit(count_fig, 0, 0, &p[i], map);
	}
	if (x <= (map->size - 2))
		c_map = fillit(count_fig, x + 1, y, &p[i], map);
	else if (x == (map->size - 1) && y <= (map->size - 2))
		c_map = fillit(count_fig, 0, y + 1, &p[i], map);
//	if (i != count_fig)
//		get_matrix(count_fig, p, map);
	return (c_map);
}
