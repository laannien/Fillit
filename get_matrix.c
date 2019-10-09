/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uheirloo <uheirloo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 20:54:28 by djoye             #+#    #+#             */
/*   Updated: 2019/10/09 15:58:53 by djoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

// Определяет размер минимального квадрата, в который помещаются фигуры
t_map		*get_matrix(int count_fig, t_tetra *p, t_map *map)
{
	int			i;
	int			j;
	
	// Ищет минимальный квадрат в зав от количества заполненных фигурами ячеек
	if (!(map->size))
	{
		map->size = 2;
		while (count_fig * 4 > map->size * map->size)
			map->size++;		
	}
	else
		map->size++;
	// Создаём указатели на начало строк в матрице (у)
	if (!(map->matrix = (char**)malloc(sizeof(char*) * (map->size + 1))))
		return (NULL);
	j = 0;
	// Создаём строки и заполняем их "."
	while (j < map->size)
	{
		i = 0;
		if (!(map->matrix[j] = (char*)malloc(sizeof(char) * (map->size + 1))))
			return (NULL);
		while (i < map->size)
		{
			map->matrix[j][i] = '.';
			i++;
		}
		map->matrix[j][i] = '\0';
		j++;
	}
	map->matrix[j] = 0;
	map = algo(count_fig, p, map);
	return (map);
}
