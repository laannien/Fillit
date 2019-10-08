/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoye <djoye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:39:16 by djoye             #+#    #+#             */
/*   Updated: 2019/10/08 16:18:28 by djoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		push(int size, int x, int y, p_point *p, char **matrix, int fig_ind)
{
	char	c;

	c = fig_ind + 'A';
	if ((x + p->x[0] >= 0 && y + p->y[0] >= 0 && x + p->x[0] <= size &&
			y + p->y[0] <= size && matrix[y + p->y[0]][x + p->x[0]] == '.') &&
			(x + p->x[1] >= 0 && y + p->y[1] >= 0 && x + p->x[1] <= size &&
			y + p->y[1] <= size && matrix[y + p->y[1]][x + p->x[1]] == '.') &&
			(x + p->x[2] >= 0 && y + p->y[2] >= 0 && x + p->x[2] <= size &&
			 y + p->y[2] <= size && matrix[y + p->y[2]][x + p->x[2]] == '.'))
	{
		matrix[y][x] = c;
		matrix[y + p->y[0]][x + p->x[0]] = c;
		matrix[y + p->y[1]][x + p->x[1]] = c;
		matrix[y + p->y[2]][x + p->x[2]] = c;
		return (1);
	}
	else return (0);
}

int main(void)
{
	p_point p;
	int size = 4;
	char **matrix;
	int j = 0;
	int i = 0;

	p.x[0] = 0;
	p.x[1] = 1;
	p.x[2] = 0;
	p.y[0] = 1;
	p.y[1] = 1;
	p.y[2] = 2;
	matrix = (char**)malloc(sizeof(char*) * (size + 1));
	while (j < size)
	{
		i = 0;
		if (!(matrix[j] = (char*)malloc(sizeof(char) * (size + 1))))
			return (1);
		while (i < size)
		{
			matrix[j][i] = '.';
			i++;
		}
		matrix[j][i] = '\0';
	//	printf("%s\n", matrix[j]);
		j++;
	}
	push(size, 0, 0, &p, matrix, 4);
	push(size, 0, 0, &p, matrix, 4);
	 j = 0;
	 while (j < size)
	 {
		printf("%s\n", matrix[j]);
		j++;
	 }
	 return (0);
}
