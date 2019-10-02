/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uheirloo <uheirloo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 20:54:28 by djoye             #+#    #+#             */
/*   Updated: 2019/10/02 17:53:07 by uheirloo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

// Определяет размер минимального квадрата, в который помещаются фигуры
// ? Возможно написать алгоритм без статической переменной ?
// ? Почему ничего не возвращает ?
void		min_square(int count_fig, int resize)
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
	matrix = (char **)malloc(sizeof(char *) * (size + 1));
	j = 0;
	while (j < size)
	{
		i = 0;
		matrix[j] = (char *)malloc(sizeof(char) * (size + 1));
		while (i < size)
			matrix[j][i++] = '.';
		matrix[j][i] = '\0';
		printf("%s\n", matrix[j]);
		j++;
	}
	matrix[j] = 0;
	return ;
}

int		main()
{
	min_square(26, 0);
	min_square(26, 1);
	min_square(26, 1);
	return (0);
}
