/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uheirloo <uheirloo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:39:16 by djoye             #+#    #+#             */
/*   Updated: 2019/10/09 11:12:19 by djoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		push_figure(int x, int y, t_tetra *p, t_map *map)
{
	if ((x + p->x[0] >= 0 && y + p->y[0] >= 0 && x + p->x[0] <= map->size &&
			y + p->y[0] <= map->size &&
			map->matrix[y + p->y[0]][x + p->x[0]] == '.') &&
			(x + p->x[1] >= 0 && y + p->y[1] >= 0 && x + p->x[1] <= map->size &&
			y + p->y[1] <= map->size &&
			map->matrix[y + p->y[1]][x + p->x[1]] == '.') &&
			(x + p->x[2] >= 0 && y + p->y[2] >= 0 && x + p->x[2] <= map->size &&
			 y + p->y[2] <= map->size &&
			 map->matrix[y + p->y[2]][x + p->x[2]] == '.'))
	{
		map->matrix[y][x] = p->letter;
		map->matrix[y + p->y[0]][x + p->x[0]] = p->letter;
		map->matrix[y + p->y[1]][x + p->x[1]] = p->letter;
		map->matrix[y + p->y[2]][x + p->x[2]] = p->letter;
		return (1);
	}
	else return (0);
}

/*int main(void)
{
	t_tetra p;
	t_map	map;
	int j = 0;
	int i = 0;

	p.x[0] = 0;
	p.x[1] = 1;
	p.x[2] = 0;
	p.y[0] = 1;
	p.y[1] = 1;
	p.y[2] = 2;
	p.letter = 'A';
	map.size = 4;
	map.matrix = (char**)malloc(sizeof(char*) * (map.size + 1));
	while (j < map.size)
	{
		i = 0;
		if (!(map.matrix[j] = (char*)malloc(sizeof(char) * (map.size + 1))))
			return (1);
		while (i < map.size)
		{
			map.matrix[j][i] = '.';
			i++;
		}
		map.matrix[j][i] = '\0';
	//	printf("%s\n", map.matrix[j]);
		j++;
	}
	push_figure(0, 0, &p, &map);
	 j = 0;
	 while (j < map.size)
	 {
		printf("%s\n", map.matrix[j]);
		j++;
	 }
	 return (0);
}
*/
