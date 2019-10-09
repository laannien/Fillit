/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uheirloo <uheirloo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 18:49:37 by djoye             #+#    #+#             */
/*   Updated: 2019/10/09 14:21:19 by uheirloo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

// Определяем размер буфера для чтения (одна фигура)
# define BUFF_SIZE 21

// Подключаем хедеры для read, write, open, close, malloc, free
# include <string.h>
# include <ctype.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>

// Подключаем хедер для prinf - УДАЛИТЬ ПЕРЕД СДАЧЕЙ
# include <stdio.h>

/* Фигуры тетрамино, записанные в виде отступов от момента первого вхождения
// ? Возможно есть смысл хранить их в виде координат?
// # define T01 t_xy T01[6] = {0, 1, 0, 2, 0, 3};
// # define T02 int T02[6] = {1, 0, 2, 0, 3, 0};
// # define T03 int T03[6] = {1, 0, 0, 1, 1, 1};
// # define T04 int T04[6] = {0, 1, 0, 2, 1, 2};
// # define T05 int T05[6] = {1, 0, 1, 1, 1, 2};
// # define T06 int T06[6] = {0, 1, 1, 0, 2, 0};
// # define T07 int T07[6] = {0, 1, -1, 1, -2, 1};
// # define T08 int T08[6] = {1, 0, 0, 1, 0, 2};
// # define T09 int T09[6] = {0, 1, 0, 2, -1, 2};
// # define T10 int T10[6] = {0, 1, 1, 1, 2, 1};
// # define T11 int T11[6] = {1, 0, 2, 0, 2, 1};
// # define T12 int T12[6] = {0, 1, 1, 1, 1, 2};
// # define T13 int T13[6] = {1, 0, 0, 1, -1, 1};
// # define T14 int T14[6] = {0, 1, 1, -1, -1, 2};
// # define T15 int T15[6] = {1, 0, 1, 1, 2, 1};
// # define T16 int T16[6] = {-1, 1, 0, 1, 1, 1};
// # define T17 int T17[6] = {-1, 1, 0, 1, 0, 2};
// # define T18 int T18[6] = {0, 1, 1, 1, 0, 2};
// # define T19 int T19[6] = {1, 0, 1, 1, 2, 0};
*/
// Структура для храниния фигуры в виде координат или отступов
typedef struct	s_tetra
{
	char		letter;
	int 		x[3];
	int 		y[3];
}				t_tetra;

// Структура для хранения матрицы карты и её размера
typedef struct	s_map
{
	int			size;
	char		**matrix;
}				t_map;

int				check_file_content(char *str, int len);
int				push_figure(int x, int y, t_tetra *p, t_map *map);
t_tetra			save_figures(char *str, t_tetra *figure, int index);
t_map        	*get_matrix(int count_fig, t_map *map);
t_map			*algo(int	count_fig, t_tetra *p, t_map *map);

#endif
