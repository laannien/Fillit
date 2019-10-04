/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uheirloo <uheirloo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 20:54:28 by djoye             #+#    #+#             */
/*   Updated: 2019/10/04 13:50:47 by uheirloo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

// Определяет размер минимального квадрата, в который помещаются фигуры
// ? Возможно написать алгоритм без статической переменной ?
char		**get_matrix(int count_fig, int resize)
{
	static int	size = 2;
	char		**matrix;
	int			i;
	int			j;
	
	// Ищет минимальный квадрат в зависимости от количества заполненных фигурами ячеек
	while (count_fig * 4 > size * size)
			size++;
	// Если в предыдущий минимальный квадрат не удалось заполнить фигурами, увеличиваем размер
	if (resize == 1)
		size++;
	// Создаём указатели на начало строк в матрице (у)
	if (!(matrix = (char**)malloc(sizeof(char*) * (size + 1))))
		return (NULL);
	j = 0;
	// Создаём строки и заполняем их "."
	while (j < size)
	{
		i = 0;
		if (!(matrix[j] = (char*)malloc(sizeof(char) * (size + 1))))
			return (NULL);
		while (i < size)
			matrix[j][i++] = '.';
		matrix[j][i] = '\0';
		printf("%s\n", matrix[j]);
		j++;
	}
	matrix[j] = 0;
	return (matrix);
}

int		main()
{
	get_matrix(26, 0);
	get_matrix(26, 1);
	get_matrix(26, 1);
	return (0);
}
